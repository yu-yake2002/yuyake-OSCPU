#include "verilated.h"
#include "Vtop.h"
#include <memory>
#include <iostream>
#include <stdint.h>
#include <assert.h>

static Vtop* dut_ptr;

#ifdef VM_TRACE         // --trace
#include <verilated_vcd_c.h>
static VerilatedVcdC* fp;      //to form *.vcd file
#endif

//mycpu运行一个周期
void next_cycle(int time){
  dut_ptr->clk = 0;
  dut_ptr->eval();
  fp->dump(time * 2 + 1);
  dut_ptr->clk = 1;
  dut_ptr->eval();
  fp->dump(time * 2 + 2);
}

//将输入的Test的字符串读取为Int64传入硬件，使其初始化读取Mem。
uint64_t char2int(char *argv){
  uint64_t re = 0;
  int i = 0;
  for(i = 0;i < 8;i++){
    if(argv[i] != '\0')
      re = (re << 8) + (uint64_t)argv[i];
    else
      break;
  }
  return re;
}

int main(int argc, char **argv) {
  Verilated::traceEverOn(true);
  printf("Enabling waves ...\n");
  fp = new VerilatedVcdC;
  dut_ptr->trace(fp, 99);
  fp->open("vlt_dump.vcd");
  dut_ptr = new Vtop;
  dut_ptr->reset = 0;
  dut_ptr->clk = 0;
  dut_ptr->eval();
  char temp[64] = "add";
  uint64_t testcase = char2int(temp);
  // initial， reset的时候imem读取对应的testbench。
  dut_ptr->reset = 1;
  dut_ptr->testcase = testcase;
  next_cycle(0);
  next_cycle(1);
  dut_ptr->reset = 0;

  for (int i = 2; i < 1002; i++) {
    next_cycle(i);
    if(dut_ptr->done == 1){
      printf("Finish Test\n");
      break;
    }
  }
  delete dut_ptr;
  return 0;
}
