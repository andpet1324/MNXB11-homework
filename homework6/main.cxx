#include <iostream>
#include <string>
auto change_int(int int_val, std::string first_arg) {
  for (int i = 0; i >= 0; i++) {
    int_val += first_arg[i];
    if (i >= static_cast<int>(first_arg.size())) {
        break;
    }
  }
    return int_val;
}

auto key_calc(int int_val, char first_arg_first_letter) {
  return (int_val ^ first_arg_first_letter * 3);
}

int main(int number_of_args, char *arg_container[]) {
  if (number_of_args == 3) {
    std::string program_name{arg_container[0]};
    auto first_arg_first_letter{*(arg_container[1])};
    auto program_name_val{program_name.size()};
    auto second_arg_string{std::atoi(arg_container[2])};
    auto int_val{0};
    std::string first_arg{arg_container[1]};

    int_val = change_int(int_val, first_arg);
    
    std::cout << int_val << std::endl;
    if ((key_calc(int_val, first_arg_first_letter)) << (program_name_val & 0x1f) == second_arg_string) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}