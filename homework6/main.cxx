#include <iostream>
#include <string>
int main(int number_of_args, char *arg_container[]) {
  if (number_of_args == 3) {
    std::string program_name{arg_container[0]};
    char first_arg_first_letter{*(arg_container[1])};
    auto program_name_val{program_name.size()};
    auto second_arg_string{std::atoi(arg_container[2])};
    auto zero1{0};
    auto zero2{0};
    std::string first_arg{arg_container[1]};
    while (true) {
      zero1 += first_arg[zero2
++];
      if (zero2
 >= static_cast<int>(first_arg.size())) {
        break;
      }
    }
    if ((zero1 ^ first_arg_first_letter * 3) << (program_name_val & 0x1f) == second_arg_string) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}