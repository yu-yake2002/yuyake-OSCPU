#include "Vtop.h"
#include <memory>
#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <assert.h>

static Vtop* dut_ptr;


//mycpu运行一个周期
void next_cycle(){
  dut_ptr->eval();
  dut_ptr->clk = 0;
  dut_ptr->eval();
  dut_ptr->clk = 1;
  dut_ptr->eval();
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
  dut_ptr = new Vtop;
  dut_ptr->reset = 0;
  dut_ptr->clk = 0;
  dut_ptr->eval();
  char temp[64] = "add";
  uint64_t testcase = char2int(temp);
  // initial， reset的时候imem读取对应的testbench。
  dut_ptr->reset = 1;
  dut_ptr->testcase = testcase;
  next_cycle();
  next_cycle();
  dut_ptr->reset = 0;

  for (int i = 0; i < 1000; i++) {
    next_cycle();
    if(dut_ptr->done == 1){
      printf("Finish Test\n");
      break;
    }
  }
  delete dut_ptr;
  return 0;
}
