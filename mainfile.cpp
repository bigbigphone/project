#include <iostream>
#include <string>
using namespace std;
int main(){
  int main_command=5;
  int product_amount=0;
  string product_name;
  
  cout<<"******************************"<<endl;
  cout<<"**Commodity Inventory System**"<<endl;
  cout<<"******************************"<<endl;
  cout<<endl;
  while (main_command!=0){
    cout<<" 1 ---- Search Commodity By Filters"<<endl;
    cout<<" 2 ---- Insert Commodity"<<endl;
    cout<<" 3 ---- Delete Commodity"<<endl;
    cout<<" 4 ---- Update Commodity Information"<<endl;
    cout<<" 0 ---- Terminate The System"<<endl;
    cout<<" Please Input The Corresponding Function Number :";
    cin>>main_command>>endl;
    if (main_command==1){
    
    }
    if (main_command==2){
      int add_command=3;
      while (add_command!=0){
        cout<<" 1 ---- Insert New Commodity"<<endl;
        cout<<" 2 ---- Insert Current Commodity"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        cout<<" Please Input The Corresponding Function Number :";
        cin>>add_command>>endl;
        
        if (add_command==2){
          cout<<" Please Input Product Name : ";
          cin>>product_name>>endl;
          cout<<" Please Input Quantity of Appendage : ";
          cin>>product_amount>>endl;
          add_function(product_name,product_amount);
        }
       
    }
      
    if (main_command==3){
      delete_function();
    }
    if (main_command==4){
      update_function();
    }
  }
  cout<<" Think You For Using The System"<<endl;
}
