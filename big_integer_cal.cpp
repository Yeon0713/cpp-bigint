#include <iostream>
#include <string>

std::string sum(std::string x, std::string y){

    std::string num1 = x;
    std::string num2 = y;
    std::string result_str;

    std::string big_num;
    std::string small_num;
  
    if (num1.size() >= num2.size()) {
        big_num = num1;
        small_num = num2;
    }
    else {
        big_num = num2;
        small_num = num1;
    }

    int diff_size = big_num.size() - small_num.size();

    int up_num = 0;     //up_num은 자릿수 계산 결과에 따라 앞자리로 넘길 수
    int cal = 0;        //cal은 각 자릿수 계산 결과

    for (int i = big_num.size() - 1; i >= diff_size; i--){
        int a = int(big_num[i] - '0');
        int b = int(small_num[i - diff_size] - '0');
        cal = a + b + up_num;
        if (cal < 10 && cal >= 0) {
            result_str += std::to_string(cal);
            up_num = 0;
        }
        else {
            result_str += std::to_string(cal - 10);
            up_num = 1;
        }
    }
    for (int i = diff_size - 1; i >= 0; i--){
        if (int(big_num[i] - '0') + up_num >= 0 && int(big_num[i] - '0' + up_num < 10)){
            result_str += std::to_string(int(big_num[i] - '0') + up_num);
            up_num = 0;
        }    
        else {
            result_str += std::to_string(int(big_num[i] - '0') + up_num - 10);
            up_num = 1;
        }
    }
    if(up_num == 1) {
        result_str += std::to_string(up_num);
    }

    std::string result;

    for (int i = 0; i < big_num.size() + 1; i++){
        result += result_str[big_num.size() - i];
    }

    return result;

}

std::string sub(std::string x, std::string y) {
    std::string num1 = x;
    std::string num2 = y;
    std::string result_str;

    std::string big_num;
    std::string small_num;

    if (x == y){
        return "0";
    }
    if (num1.size() > num2.size()) {
        big_num = num1;
        small_num = num2;
    }
    else {
        big_num = num2;
        small_num = num1;
    }

    int diff_size = big_num.size() - small_num.size();

    int down_num = 0;      //
    int cal = 0;

    for (int i = big_num.size() - 1; i >= diff_size; i--) {
        int a = int(big_num[i] - '0');
        int b = int(small_num[i - diff_size] - '0');
        cal = a - b - down_num;
        if (cal >= 0){
            result_str += std::to_string(cal);
            down_num = 0;
        }
        else {
            result_str += std::to_string(cal + 10);
            down_num = 1;
        }
    }

    for (int i = diff_size - 1; i >= 0; i--){
        if (big_num[i] - '0' - down_num >= 0){
            result_str += std::to_string(big_num[i] - '0' - down_num);
            down_num = 0;
        }
        else{
            result_str += std::to_string(big_num[i] - '0' - down_num + 10);
            down_num = 1;
        }
    }

    if(x.size() > y.size()) {
        result_str += "";
    }
    else if (x.size() == y.size()){
        for(int i = 0; i < x.size(); i++){
            if (int(x[i] - '0') > int(y[i] - '0')){
                result_str += "";
            }
            else if (int(x[i] - '0') < int(y[i] - '0')){
                result_str += "-";
            }
        }
        
    }
    else {
        result_str += "-";
    }

    std::string result;

    for (int i = 0; i < big_num.size() + 1; i++){
        result += result_str[big_num.size() - i];
    }

    int result_size = result.size();

    if (int(result[0]) == int('-')){
        int i = 0;
        while (i < result_size - 1){
            if (int(result[1] - '0') == 0) {
                result.erase(result.begin() + 1);
            }
            else{
                break;
            }
            i++;
        }
        
    }
    else{
        int i = 0;
        while (i < result_size - 1) {
            if (int(result[0] - '0') == 0) {
                result.erase(result.begin());
            }
            else {
                break;
            }
            i++;
        }
    }
    
    
    return result;
}



int main(void){
    std::string num1;
    std::string num2;

    std::cout << "First number  >> ";
    std::cin >> num1;
    std::cout << "Second number >> ";
    std::cin >> num2;

    std::cout << "Sum           >> " << sum(num1, num2) << "\n";
    std::cout << "Sub           >> " << sub(num1, num2) << "\n";
    
}