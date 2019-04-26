#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int othershop(string *name, int *product_quantity)
{
  ifstream fin("Othershopstock.txt");
  string name2,shop_name;
  int quantity,boolean_n = 0;
  
  if (fin.fail()){
    exit(1);
  }
  else{
    ofstream fout;
    fout.open("temp.txt", ios::app);
    if (fout.fail()){
      exit(1);
    }
    while (fin>>name2){
      fin>>quantity>>shop_name;
      if (name2 != *name){
        fout << name2 << quantity << shop_name << endl;
      }
      if (name2==*name && quantity > *product_quantity){
        cout<<shop_name<<" is in stock. There are "<<quantity<<" pieces currently."<<endl;
        if (*product_quantity == -1){
          continue;
        }
        else if (*product_quantity > 0){
          quantity = quantity - *product_quantity;
          fout << name2 << quantity << shop_name << endl;
          boolean_n = 1;
        }
      }
      if (name2==*name && quantity < *product_quantity){
        cout << "The actual amount of the stock is fewer than the requested amount!" << endl;
        fin.close();
        fout.close();
        return boolean_n;
      }
    }
    fout.close();
  }
  fin.close();
  if (boolean_n == 1){
    remove("Othershopstock.txt");
    rename("temp.txt", "Othershopstock.txt");
  }
  return boolean_n;
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
    while (fin>>name){
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
  string manufacturer;
  int quantity;
  double price;
  string *name = new string;
  int *p;
  p = new int;
  *p = -1;
  
  if (fin.fail()){
    exit(1);
  }
  else{
    while (fin>>*name){
      fin>>quantity>>price>>manufacturer;
      if (quantity==0){
        cout<<*name<<"  $"<<price<<"  "<<manufacturer<<endl;
        othershop(name, p);
      }
      else{
        continue;
      }
    }
  }
  fin.close();
  delete p;
}

int allstock(string *product_name)
{
  ifstream fin("stock_info.txt");
  string name,manufacturer;
  int quantity;
  double price;
  
  if (fin.fail()){
    exit(1);
  }
  while (fin>>name){
    fin>>quantity>>price>>manufacturer;
    if (*product_name == "all"){
      cout<<name<<"  "<<quantity<<" Pieces"<<"  $"<<price<<"  "<<manufacturer<<endl;
    }
    else{
      if (name == *product_name){
        fin.close();
        return 1;
      }
    }
  }
  fin.close();
  return 0;
}

void insert_new_function(string product_name,int *product_amount,double product_price,string product_manufacturer)
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
    cout << endl;
    cout << "The product " << product_name << " already exists!" << endl;
    cout << endl;
  }
  else{
    ofstream fout;
    fout.open("stock_info.txt", ios::app);
    if (fout.fail()){
      exit(1);
    }
    fout << product_name << " " << *product_amount << " " << product_price << " " << product_manufacturer << endl;
    fout.close();
    cout << endl;
    cout << product_name << " is inserted to the commodity inventory system." << endl;
    cout << endl;
  }
} 

void add_function(string *product_name,int *product_amount)
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
    if (temp_name != *product_name){
      fout << temp_name << " " << temp_amount << " " << temp_price << " " << temp_manufacturer << endl;
    }
    else{
      n += 1;
      *product_amount = temp_amount + *product_amount;
      fout << temp_name << " " << *product_amount << " " << temp_price << " " << temp_manufacturer << endl;
      cout << endl;
      cout << "The fore-updated product quantity is " << temp_amount << endl;
      cout << "The updated quantity is " << *product_amount << endl;
      cout << endl;
    }
  }
  if (n == 0){
    cout << endl;
    cout << "The product " << *product_name << " does not exist!" << endl;
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

void reduce_function(string *product_name,int *product_amount)
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
    if (temp_name != *product_name){
      fout << temp_name << " " << temp_amount << " " << temp_price << " " << temp_manufacturer << endl;
    }
    else{
      n += 1;
      total_amount = temp_amount - *product_amount;
      if (total_amount >= 0){
        fout << temp_name << " " << total_amount << " " << temp_price << " " << temp_manufacturer << endl;
        cout << endl;
        cout << "The fore-updated product quantity is " << temp_amount << endl;
        cout << "The updated quantity is " << total_amount << endl;
        cout << endl;
      }
      else{
        cout << endl;
        cout << "The quantity of " << *product_name << " is fewer than " << *product_amount << "!" << endl;
        cout << endl;
      }
      if (total_amount < 1){
        cout << endl;
        cout << "** Alert! It is out-of-stock! **" << total_amount << endl;
        cout << endl;
      }
    }
  }
  if (n == 0){
    cout << endl;
    cout << "The product " << *product_name << " does not exist!" << endl;
    cout << endl;
  }
  fin.close();
  fout.close();
  remove("stock_info.txt");
  rename("temp.txt", "stock_info.txt");
}

void update_function(string product_name,string new_product_name,int new_product_quantity,double new_product_price,string new_product_manufacturer)
{
  string original_product_name,original_product_manufacturer;
  int original_product_quantity;
  double original_product_price;
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
      while(fin>>original_product_name){
        fin>>original_product_quantity>>original_product_price>>original_product_manufacturer;
        if (original_product_name==product_name){
          n=1;
          if (new_product_name!=""){
            original_product_name=new_product_name;
          }
          if (new_product_quantity!=-1){
            original_product_quantity=new_product_quantity;
          }
          if (new_product_price!=-1){
            original_product_price=new_product_price;
          }
          if (new_product_manufacturer!=""){
            original_product_manufacturer=new_product_manufacturer;
          }
        }
        fout<<original_product_name<<" "<<original_product_quantity<<" "<<original_product_price<<" "<<original_product_manufacturer<<endl;
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
        if (original_product_quantity < 1){
          cout << endl;
          cout << "** Alert! It is out-of-stock! **" << original_product_quantity << endl;
          cout << endl;
        }
      }
    }
  } 
}

int main(){
  int main_command=6;
  int product_amount=0;
  double product_price=0.0;
  string product_name,product_manufacturer;
  
  cout<<"******************************"<<endl;
  cout<<"**Commodity Inventory System**"<<endl;
  cout<<"******************************"<<endl;
  cout<<endl;
  while (main_command!=0){
    cout<<" 1 ---- Search Commodity"<<endl;
    cout<<" 2 ---- Insert Commodity"<<endl;
    cout<<" 3 ---- Delete Commodity"<<endl;
    cout<<" 4 ---- Update Commodity Information"<<endl;
    cout<<" 5 ---- Dispatch Commodity Internally"<<endl;
    cout<<" 0 ---- Exit The Program"<<endl;
    cout<<" Please Input The Corresponding Function Number :";
    cin>>main_command;
    cout<<"================================================================================"<<endl;
   
    if (main_command==1){
      int search_command=4;
      while (search_command!=0){
        cout<<" 1 ---- Show In-Stock"<<endl;
        cout<<" 2 ---- Show Out-of-Stock"<<endl;
        cout<<" 3 ---- Show All Stocks"<<endl;
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
        if (search_command==3){
          string *s;
          s = new string;
          *s = "all";
          allstock(s);
          delete s;
        }       cout<<"================================================================================"<<endl;
      }
    }
    
    if (main_command==2){
      int add_command=3;
      int *product_quantity = new int;
        
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
          cin>>*product_quantity;
          cout<<" Please Input Price : ";
          cin>>product_price;
          cout<<" Please Input Manufacturer : ";
          cin>>product_manufacturer;
          insert_new_function(product_name,product_quantity,product_price,product_manufacturer);
        }
        if (add_command==2){
          string *product_name = new string;
          cout<<" Please Input Product Name : ";
          cin>>*product_name;
          cout<<" Please Input Quantity of Appendage : ";
          cin>>*product_quantity;
          add_function(product_name,product_quantity);
          delete product_name;
        }
      }  
      delete product_quantity;
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
          int *product_quantity = new int;
          string *product_name = new string;
          cout<<" Please Input Product Name : ";
          cin>>*product_name;
          cout<<" Please Input Quantity of Removal : ";
          cin>>*product_quantity;
          reduce_function(product_name,product_quantity);
        }
      } 
      cout<<"================================================================================"<<endl;
    }

    if (main_command==4){
      int update_command=5;
      string new_product_name="",new_product_manufacturer="";
      int new_product_quantity=-1;
      double new_product_price=-1;
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
    
    if (main_command == 5){
      int dispatch_command = 3;
      string *product_name = new string;
      int *product_quantity = new int;
      
      while (dispatch_command!=0){
        cout<<" 1 ---- Request Commodity To the Shop"<<endl;
        cout<<" 2 ---- Requested to Dispatch Commodity From the Shop"<<endl;
        cout<<" 0 ---- Return to Main Menu"<<endl;
        cout<<" Please Input The Corresponding Function Number :";
        cin >> dispatch_command;
        if (dispatch_command==1){
          cout<<" Please Input Requested Product Name : ";
          cin>>*product_name;
          cout<<" Please Input Requested Product Quantity : ";
          cin>>*product_quantity;
          if (othershop(product_name,product_quantity)==1){
            add_function(product_name,product_quantity);
          }
        }
        if (dispatch_command==2){
          cout<<" Please Input Requested Product Name : ";
          cin>>*product_name;
          cout<<" Please Input Requested Product Quantity : ";
          cin>>*product_quantity;
          if (allstock(product_name)==1){
            reduce_function(product_name,product_quantity);
          }
        }
      }
      delete product_name;
      delete product_quantity;
      cout<<"================================================================================"<<endl;
    }
      
  }
  cout<<" Thank You For Using The System"<<endl;
}
