#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void othershop(string name)
{
  ifstream fin("Othershopstock.txt");
  string name2,shop_name;
  int quantity;
  
  if (fin.fail()){
    exit(1);
  }
  else{
    while (fin>>name2){
      fin>>quantity>>shop_name;
      if (name2==name){
        cout<<shop_name<<" is in stock. "<<quantity<<" pieces are available."<<endl;
      }
      else{
        continue;
      }
    }
  }
  fin.close();
}

void show_instock()
{
  ifstream fin("stock_info.txt");
  string name,manufacturer;
  int quantity;
  double price;
  
  if (fin.fail()){
    exit(1);
  }
  else{
    while (fin>>name ){
      fin>>quantity>>price>>manufacturer;
      if (quantity==0){
        continue;
      }
      else{
        cout<<name<<"  "<<quantity<<" Pieces"<<"  $"<<price<<"  "<<manufacturer<<endl;
      }
    }
  }
  fin.close();
}

void show_outofstock()
{
  ifstream fin("stock_info.txt");
  string name,manufacturer;
  int quantity;
  double price;
  
  if (fin.fail()){
    exit(1);
  }
  else{
    while (fin>>name ){
      fin>>quantity>>price>>manufacturer;
      if (quantity==0){
        cout<<name<<"  $"<<price<<"  "<<manufacturer<<endl;
        othershop(name);
      }
      else{
        continue;
      }
    }
  }
  fin.close();
}

void insert_new_function(string product_name,int product_amount,double product_price,string product_manufacturer)
{
  string temp_name,temp_mfr;
  int temp_amt;
  double temp_p;
  int n = 0;
  
  ifstream fin;
  fin.open("stock_info.txt");
  if (fin.fail()){
    exit(1);
  }
  while (fin >> temp_name){
    fin >> temp_amt >> temp_p >> temp_mfr;
    if (temp_name == product_name){
      n += 1;
    }
  }
  fin.close();
  if (n > 0){
    cout << "The product " << product_name << " already exists!" << endl;
    cout << endl;
  }
  else{
    ofstream fout;
    fout.open("stock_info.txt", ios::app);
    if (fout.fail()){
      exit(1);
    }
    fout << product_name << " " << product_amount << " " << product_price << " " << product_manufacturer << endl;
    fout.close();
    cout << endl;
    cout << product_name << " is inserted to the commodity inventory system." << endl;
    cout << endl;
  }
} 

void add_function(string product_name,int product_amount)
{
  string temp_name, temp_manufacturer;
  int temp_amount,total_amount; // no total_amount, use dynamic variable, same in reduce_function
  double temp_price;
  int n = 0;
  
  ifstream fin;
  fin.open("stock_info.txt");
  if (fin.fail()){
    exit(1);
  }
  ofstream fout;
  fout.open("temp.txt", ios::app);
  if (fout.fail()){
    exit(1);
  }
  while (fin >> temp_name){
    fin >> temp_amount >> temp_price >> temp_manufacturer;
    if (temp_name != product_name){
      fout << temp_name << " " << temp_amount << " " << temp_price << " " << temp_manufacturer << endl;
    }
    else{
      n += 1;
      total_amount = temp_amount + product_amount;
      fout << temp_name << " " << total_amount << " " << temp_price << " " << temp_manufacturer << endl;
      cout << endl;
      cout << "The fore-updated product quantity is " << temp_amount << endl;
      cout << "The updated quantity is " << total_amount << endl;
      cout << endl;
    }
  }
  if (n == 0){
    cout << "The product " << product_name << " does not exist!" << endl;
    cout << endl;
  }
  fin.close();
  fout.close();
  remove("stock_info.txt");
  rename("temp.txt", "stock_info.txt");
}

void delete_function(string product_name)
{
  string temp_name, temp_manufacturer;
  int temp_amount;
  double temp_price;
  int n = 0;
  
  ifstream fin;
  fin.open("stock_info.txt");
  if (fin.fail()){
    exit(1);
  }
  ofstream fout;
  fout.open("temp.txt", ios::app);
  if (fout.fail()){
    exit(1);
  }
  while (fin >> temp_name){
    fin >> temp_amount >> temp_price >> temp_manufacturer;
    if (temp_name != product_name){
      fout << temp_name << " " << temp_amount << " " << temp_price << " " << temp_manufacturer << endl;
    }
    else{
      n += 1;
      cout << endl;
      cout << "The removed product is " << product_name << endl;
      cout << endl;
    }
  }
  if (n == 0){
    cout << endl;
    cout << "The product " << product_name << " does not exist!" << endl;
    cout << endl;
  }
  fin.close();
  fout.close();
  remove("stock_info.txt");
  rename("temp.txt", "stock_info.txt");
}

void reduce_function(string product_name,int product_amount)
{
  string temp_name, temp_manufacturer;
  int temp_amount,total_amount;
  double temp_price;
  int n = 0;
  
  ifstream fin;
  fin.open("stock_info.txt");
  if (fin.fail()){
    exit(1);
  }
  ofstream fout;
  fout.open("temp.txt", ios::app);
  if (fout.fail()){
    exit(1);
  }
  while (fin >> temp_name){
    fin >> temp_amount >> temp_price >> temp_manufacturer;
    if (temp_name != product_name){
      fout << temp_name << " " << temp_amount << " " << temp_price << " " << temp_manufacturer << endl;
    }
    else{
      n += 1;
      total_amount = temp_amount - product_amount;
      if (total_amount >= 0){
        fout << temp_name << " " << total_amount << " " << temp_price << " " << temp_manufacturer << endl;
        cout << endl;
        cout << "The fore-updated product quantity is " << temp_amount << endl;
        cout << "The updated quantity is " << total_amount << endl;
        cout << endl;
      }
      else{
        cout << "The quantity of " << product_name << " is fewer than " << product_amount << "!" << endl;
        cout << endl;
      }
    }
  }
  if (n == 0){
    cout << "The product " << product_name << " does not exist!" << endl;
    cout << endl;
  }
  fin.close();
  fout.close();
  remove("stock_info.txt");
  rename("temp.txt", "stock_info.txt");
}

void update_function(string product_name,string new_product_name,int new_product_quantity,double new_product_price,string new_product_manufacturer)
{
  string orginal_product_name,orginal_product_manufacturer;
  int orginal_product_quantity;
  double orginal_product_price;
  int n=0;
  
  ifstream fin("stock_info.txt");
  if (fin.fail()){
    exit(1);
  }
  else{
    ofstream fout;
    fout.open("temp.txt", ios::app);
    if (fout.fail()){
      exit(1);
    }
    else{
      while(fin>>orginal_product_name){
        fin>>orginal_product_quantity>>orginal_product_price>>orginal_product_manufacturer;
        if (orginal_product_name==product_name){
          n=1;
          if (new_product_name!=""){
            orginal_product_name=new_product_name;
          }
          if (new_product_quantity!=-1){
            orginal_product_quantity=new_product_quantity;
          }
          if (new_product_price!=-1){
            orginal_product_price=new_product_price;
          }
          if (new_product_manufacturer!=""){
            orginal_product_manufacturer=new_product_manufacturer;
          }
        }
        fout<<orginal_product_name<<" "<<orginal_product_quantity<<" "<<orginal_product_price<<" "<<orginal_product_manufacturer<<endl;
      }
      fin.close();
      fout.close(); 
      if (n==0){
        cout<<"Sorry, the input item does not exist"<<endl;
      }
      else{
        remove("stock_info.txt");
        rename("temp.txt", "stock_info.txt");
        cout<<"The information has been updated"<<endl;
      }
    }
  } 
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
    cout<<" 0 ---- Exit The Program"<<endl;
    cout<<" Please Input The Corresponding Function Number :";
    cin>>main_command;
    cout<<"================================================================================"<<endl;
   
    if (main_command==1){
      int search_command=3;
      while (search_command!=0){
        cout<<" 1 ---- Show In-Stock"<<endl;
        cout<<" 2 ---- Show Out-of-Stock"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        cout<<" Please Input The Corrsponding Function Number : ";
        cin>>search_command;
        cout<<endl;
        if (search_command==1){
          show_instock();
        }
        if (search_command==2){
          show_outofstock();
        }
        cout<<"================================================================================"<<endl;
      }
    }
    
    if (main_command==2){
      string product_name, product_manufacturer;
      int add_command=3, product_amount;
      double product_price;
      while (add_command!=0){
        cout<<" 1 ---- Insert New Commodity"<<endl;
        cout<<" 2 ---- Insert Current Commodity"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        cout<<" Please Input The Corresponding Function Number : ";
        cin>>add_command;
        cout<<endl;
        if (add_command==1){
          cout<<" Please Input Product Name : ";
          cin>>product_name;
          cout<<" Please Input Quantity : ";
          cin>>product_amount;
          cout<<" Please Input Price : ";
          cin>>product_price;
          cout<<" Please Input Manufacturer : ";
          cin>>product_manufacturer;
          insert_new_function(product_name,product_amount,product_price,product_manufacturer);
        }
        if (add_command==2){
          cout<<" Please Input Product Name : ";
          cin>>product_name;
          cout<<" Please Input Quantity of Appendage : ";
          cin>>product_amount;
          add_function(product_name,product_amount);
        }
      }  
      cout<<"================================================================================"<<endl;    
    }

    if (main_command==3){
      int delete_command=3;
      while (delete_command!=0){
        cout<<" 1 ---- Delete Commodity"<<endl;
        cout<<" 2 ---- Reduce Commodity Quantity"<<endl;
        cout<<" 0 ---- Return To Previous Page"<<endl;
        cout<<" Please Input The Corresponding Function Number :";
        cin>>delete_command;
        cout<<endl;
        if (delete_command==1){
          cout<<" Please Input Product Name : ";
          cin>>product_name;
          delete_function(product_name);
        }
        if (delete_command==2){
          cout<<" Please Input Product Name : ";
          cin>>product_name;
          cout<<" Please Input Quantity of Removal : ";
          cin>>product_amount;
          reduce_function(product_name,product_amount);
        }
      } 
      cout<<"================================================================================"<<endl;
    }

    if (main_command==4){
      int update_command=5;
      string new_product_name="",new_product_manufacturer="";
      int new_product_quantity=-1;
      double new_product_price=-1;
      // if no input of new item ,break in the corresponding function =
      cout<<" Please Input Product Name : ";
      cin>>product_name;
      cout<<endl;
      while (update_command!=0){
        cout<<" 1 ---- Change Commodity Name"<<endl;
        cout<<" 2 ---- Change Commodity Quantity"<<endl;
        cout<<" 3 ---- Change Commodity Price"<<endl;
        cout<<" 4 ---- Change Commodity Manufacturer"<<endl;
        cout<<" 0 ---- Finishing the Changing Process"<<endl;
        cout<<" Please Input The Corresponding Function Number :";
        cin >> update_command;
        if (update_command==1){
          cout<<" Please Input New Product Name : ";
          cin>>new_product_name;
        }
        if (update_command==2){
          cout<<" Please Input New Product Quantity : ";
          cin>>new_product_quantity;
        }
        if (update_command==3){
          cout<<" Please Input New Product Price : ";
          cin>>new_product_price;
        }
        if (update_command==4){
          cout<<" Please Input New Product Manufacturer : ";
          cin>>new_product_manufacturer;
        }
      }
      update_function(product_name,new_product_name,new_product_quantity,new_product_price,new_product_manufacturer);
      cout<<"================================================================================"<<endl;
    }
  }
  cout<<" Thank You For Using The System"<<endl;
}
