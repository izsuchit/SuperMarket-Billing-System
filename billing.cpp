#include<iostream>
#include<fstream>
using namespace std;

class Shopping
{
private:
      int pcode;
      float price;
      float discount;
      string pname;

public:
   void menu();
   void administrator();
   void buyer();
   void add();
   void edit();
   void del();
   void list();
   void reciept();
};

void Shopping :: menu()
{  
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________________________________________\n";
    cout<<"\t\t\t\t                                                                   \n";
    cout<<"\t\t\t\t                      Supermarket Main Menu                        \n";
    cout<<"\t\t\t\t                                                                   \n";
    cout<<"\t\t\t\t___________________________________________________________________\n";
    cout<<"\t\t\t\t                                                                   \n";
    cout<<"\t\t\t\t  1) Administrator       |\n";
    cout<<"\t\t\t\t                         |\n";
    cout<<"\t\t\t\t  2) Buyer               |\n";
    cout<<"\t\t\t\t                         |\n";
    cout<<"\t\t\t\t  3) Exit                |\n";
    cout<<"\t\t\t\t                         |\n";
    cout<<"\t\t\t\t  Please Select!!        |\n";
    cin>>choice;
    switch(choice){
        case 1:
              cout<<"\t\t\t Please Login \n";
              cout<<"\t\t\t Enter Email  \n";
              cin>>email;
              cout<<"\t\t\t Enter Password \n";
              cin>>password;
              if(email=="suchit20@iitk.ac.in" && password=="Sonu@123"){
                administrator();
              }
              else{
                cout<<"Invalid email/password";
              }
              break;

         case 2: buyer();
                 break;
         case 3: exit(0);

         default : cout<<"Please Select from the given option\n";     
    }
 goto m;
}

void Shopping ::administrator()
{   
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu :";
    cout<<"\n\t\t\t|_____1.) Add the product____|";
    cout<<"\n\t\t\t|_____2.)Modify the product____|";
    cout<<"\n\t\t\t|_____3.)Delete the product____|";
    cout<<"\n\t\t\t|_____4.)Back to Main Menu_____|";
    cout<<"\n\t\t\t\t  Please Select!!        |\n";
    cin>>choice;
    switch(choice)
    {
        case 1: add();
                break;
        case 2: edit();
                break;
        case 3: del();
                break;
        case 4:menu();
               break;
         default : cout<<"Invalid Choice!!";      
    }
    goto m;
}
void Shopping ::buyer()
{   
    m:
    int choice;
    cout<<"\t\t\t___________Buyer__________________\n";
    cout<<"\t\t\t____________\n";
    cout<<"\t\t\t          \n";
    cout<<"\t\t\t 1) Buy Product \n";
    cout<<"\t\t\t          \n";
    cout<<"\t\t\t 2) Go Back \n";
    cout<<"\t\t\t Enter your Choice \n";
    cin>>choice;

    switch(choice){
        
        case 1:
              reciept();
              break;

        case 2:
              menu();
              break;
        default :
                 cout<<" Invalid Choice ";            
    }

  goto m;
}
void Shopping ::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product ";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>discount;
    data.open("database.txt",ios::in);
    if(!data){

        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    
    if(token==1){
        goto m;
    }else{
      data.open("database.txt",ios::app | ios::out);
      data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
      data.close();  
    }
    }
    cout<<"Record inserted !!";
}

void Shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\nFile doesn't exist! ";
    }else{
        data.open("database1.txt",ios::app | ios ::out);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited !";
                token++;
            }else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";

            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found sorry!!";
        }
    }
}

void Shopping :: del()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete Product ";
    cout<<"\n\n\t Product code : "; 
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }else{
                data1>>pcode>>pname>>price>>discount;
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        delete("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record not found !";
        }
    }
}

void Shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n____________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n____________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;

    }
    data.close();
}

void Shopping ::reciept()
{    
    
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t\t RECIEPT  ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database";

    }else{
        data.close();
        list();
        cout<<"\n_________________________________\n";
        cout<<"\n|                                 \n";
        cout<<"\n    Please Place the order        \n";
        cout<<"\n|                                \n";

        do{
            m:
            cout<<"\n\n Enter Product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n Duplicate product code. Please try Again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else no";
            cin>>choice;
        }while(choice=='y');

        cout<<"\n\n\t\t\t___________RECIEPT______________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\tAmount\tAmoutn with discout\n";

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total+=dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
      data.close();
    }
    cout<<"\n\n_____________________________";
    cout<<"\n  Total Amount :"<<total;
}
int main(){
    Shopping s;
    s.menu();

}
