#include <iostream>
#include <string>
using namespace std;
void show_instock();
{
}
void show_outofstock();
{
}
void insert_new_function(string product_name,int product_amount,double product_price,string product_manufacturer);
{
} 
void add_function(string product_name,int product_amount);
{
}
void delete_function(string product_name);
{
}
void reduce_function(string product_name,int product_amount);
{
}
void update_function(string new_product_name,int new_product_quantity,double new_product_price,string new_product_manufacturer);
{
}

int main(){
  int main_command=5;
  int product_amount=0;
  double product_price=0.0;
  string product_name,product_manufacturer;
  
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
      int search_command=3;
      while (search_command!=0){
        cout<<" 1 ---- Show In-Stock"<<endl;
        cout<<" 2 ---- Show Out-of-Stock"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        if (search_command==1){
          show_instock();
        }
        if (search_command==2){
          show_outofstock();
        }
        
      }
    
    }
    if (main_command==2){
      int add_command=3;
      while (add_command!=0){
        cout<<" 1 ---- Insert New Commodity"<<endl;
        cout<<" 2 ---- Insert Current Commodity"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        cout<<" Please Input The Corresponding Function Number :";
        cin>>add_command>>endl;
        cout<<endl;
        if (add_command==1){
          cout<<" Please Input Product Name : ";
          cin>>product_name>>endl;
          cout<<" Please Input Quantity : ";
          cin>>product_amount>>endl;
          cout<<" Please Input Price : ";
          cin>>product_price>>endl;
          cout<<" Please Input Manufacturer : ";
          cin>>product_manufacturer>>endl;
          insert_new_function(product_name,product_amount,product_price,product_manufacturer);
        }
        
        if (add_command==2){
          cout<<" Please Input Product Name : ";
          cin>>product_name>>endl;
          cout<<" Please Input Quantity of Appendage : ";
          cin>>product_amount>>endl;
          add_function(product_name,product_amount);
        }
       
    }
    // XXXXXXXXXXXXXX
    if (main_command==3){
      int delete_command=3;
      while (delete_command!=0){
        cout<<" 1 ---- Delete Commodity"<<endl;
        cout<<" 2 ---- Reduce Commodity Quantity"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        cout<<" Please Input The Corresponding Function Number :";
        cin>>delete_command>>endl;
        cout<<endl;
        if (delete_command==1){
          cout<<" Please Input Product Name : ";
          cin>>product_name>>endl;
          delete_function(product_name);
        }
        if (delete_command==2){
          cout<<" Please Input Product Name : ";
          cin>>product_name>>endl;
          cout<<" Please Input Quantity of Removal : ";
          cin>>product_amount>>endl;
          reduce_function(product_name,product_amount);
        }     
    }
    //XXXXXXXXXXXXX
    if (main_command==4){
      int update_command=5;
      string new_product_name='nothing',new_product_manufacturer='nothing';
      int new_product_quantity=-1;
      double new_product_price=-1;
      // if no input of new item ,break in the corresponding function =
      cout<<" Please Input Product Name : ";
      cin>>product_name>>endl;
      cout<<endl;
      while (update_command!=0){
        cout<<" 1 ---- Change Commodity Name"<<endl;
        cout<<" 2 ---- Change Commodity Quantity"<<endl;
        cout<<" 3 ---- Change Commodity Price"<<endl;
        cout<<" 4 ---- Change Commodity Manufacturer"<<endl;
        cout<<" 0 ---- Return To Previous Page<<"endl;
        cout<<" Please Input The Corresponding Function Number :";
        if (update_command==1){
          cout<<" Please Input New Product Name : ";
          cin>>new_product_name>>endl;
        }
        if (update_command==2){
          cout<<" Please Input New Product Quantity : ";
          cin>>new_product_quantity>>endl;
        }
        if (update_command==3){
          cout<<" Please Input New Product Price : ";
          cin>>new_product_price>>endl;
        }
        if (update_command==4){
          cout<<" Please Input New Product Manufacturer : ";
          cin>>new_product_manufacturer>>endl;
        }
      }
      update_function(new_product_name,new_product_quantity,new_product_price,new_product_manufacturer);
    }
  }
  cout<<" Think You For Using The System"<<endl;
}
