#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <direct.h>
using namespace std;

int ID,Cnum = 0,OrderID,SSumtotal = 0;
string Pid[100] = {};
string Pname[100] = {};
string PthickS[100] = {};
string PthickM[100] = {};
string PthickL[100] = {};
string PthinS[100] = {};
string PthinM[100] = {};
string PthinL[100] = {};
string PpriceS[100] = {};
string PpriceM[100] = {};
string PpriceL[100] = {};

int Oid[3] = {};
int Ono[3] = {};
string Osize[3] = {};
int Oquan[3] = {};
int Ofour[3] = {};
// int Osum[3] = {};
// int Osumtotal[3] = {};

string Osday[30000] = {};

struct Product
{
    int id;
    string name;
    string priceS;
    string priceM;
    string priceL;
    string thickS;
    string thickM;
    string thickL;
    string thinS;
    string thinM;
    string thinL;
};

struct Orders
{
    int OrderIds;
    int OrderQl;
    int OrderPid;
    int Orderflour;
    string OrderSize;
    int OrderQ;
    int OrderTT;
    int Orderwday;
    int Orderday;
    int Ordermount;
    int Orderyear;
    string Ordertime;
};


void Addproduct()
{
    Product pd;
    cout << "Enter Pizza name : ";
    cin.get();
    getline(cin, pd.name);
    cout << "Enter quantity Pizzathick S : ";
    cin >> pd.thickS;
    cout << "Enter quantity Pizzathick M : ";
    cin >> pd.thickM;
    cout << "Enter quantity Pizzathick L : ";
    cin >> pd.thickL;
    cout << "Enter quantity Pizzathin S : ";
    cin >> pd.thinS;
    cout << "Enter quantity Pizzathin M : ";
    cin >> pd.thinM;
    cout << "Enter quantity Pizzathin L : ";
    cin >> pd.thinL;
    cout << "Enter Price PizzaSize S : ";
    cin >> pd.priceS;
    cout << "Enter Price PizzaSize M : ";
    cin >> pd.priceM;
    cout << "Enter Price PizzaSize L : ";
    cin >> pd.priceL;
    ID++;

    ofstream write;
    write.open("C:/ProjectPizza/product.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << pd.name;
    write << "\n" << pd.thickS;
    write << "\n" << pd.thickM;
    write << "\n" << pd.thickL;
    write << "\n" << pd.thinS;
    write << "\n" << pd.thinM;
    write << "\n" << pd.thinL;
    write << "\n" << pd.priceS;
    write << "\n" << pd.priceM;
    write << "\n" << pd.priceL;
    write.close();
    write.open("C:/ProjectPizza/id.txt");
    write << ID;
    write.close();
    cout << "Data save to file" << endl;
}

void print(Product s)
{
    int SiTkS = 0, SiTkM = 0, SiTkL = 0, SiTnS = 0, SiTnM = 0, SiTnL = 0,Sumtotol = 0;

    stringstream STk,MTk,LTk,STn,MTn,LTn;
    STk << s.thickS;
    STk >> SiTkS;
    MTk << s.thickM;
    MTk >> SiTkM;
    LTk << s.thickL;
    LTk >> SiTkL;
    STn << s.thinS;
    STn >> SiTnS;
    MTn << s.thinM;
    MTn >> SiTnM;
    LTn << s.thinL;
    LTn >> SiTnL;

    Sumtotol = SiTkS + SiTkM + SiTkL + SiTnS + SiTnM + SiTnL;

    cout << right << ":" << setw(3) << s.id << " : " << setw(20) << s.name << " : " << setw(7) << s.thickS << " : " << setw(6) << s.thinS
         << " : " << setw(7) << s.thickM << " : " << setw(6) << s.thinM << " : " << setw(7) << s.thickL << " : " << setw(6) << s.thinL
         << " : " << setw(7) << s.priceS << " :" << setw(8) << s.priceM << " :" << setw(8) << s.priceL << " :" 
         << setw(14) << (Sumtotol) << " :" << endl;
}

void Readdata()
{
    Product pd;
    ifstream read;
    read.open("C:/ProjectPizza/product.txt");
    cout << "+==================================================================================================================================+" << endl;
    cout << ": ID :         Name         : thick S : thin S : thick M : thin M : thick L : thin L : Price S : Price M : Price L : QuantityTotal :" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------------------+" << endl;
    while (!read.eof())
    {
        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.thickS;
        read >> pd.thickM;
        read >> pd.thickL;
        read >> pd.thinS;
        read >> pd.thinM;
        read >> pd.thinL;
        read >> pd.priceS;
        read >> pd.priceM;
        read >> pd.priceL;
        print(pd);
    }
    cout << "+==================================================================================================================================+" << endl;
    read.close();
}

void Productlist()
{
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    ifstream read;
    read.open("C:/ProjectPizza/product.txt");
    int x = 0;
    cout << "+==================================================================================================================+" << endl;
    cout << ": ID :         Name         : thick S : thin S : thick M : thin M : thick L : thin L : Price S : Price M : Price L :" << endl;
    cout << "+------------------------------------------------------------------------------------------------------------------+" << endl;

    while (!read.eof())
    {
        string strid;

        read >> pd.id;
        read.ignore();
        getline(read, pd.name);
        read >> pd.thickS;
        read >> pd.thickM;
        read >> pd.thickL;
        read >> pd.thinS;
        read >> pd.thinM;
        read >> pd.thinL;
        read >> pd.priceS;
        read >> pd.priceM;
        read >> pd.priceL;

        strid = to_string(pd.id);

        Pid[x] = strid;
        Pname[x] = pd.name;
        PthickS[x] = pd.thickS;
        PthickM[x] = pd.thickM;
        PthickL[x] = pd.thickL;
        PthinS[x] = pd.thinS;
        PthinM[x] = pd.thinM;
        PthinL[x] = pd.thinL;
        PpriceS[x] = pd.priceS;
        PpriceM[x] = pd.priceM;
        PpriceL[x] = pd.priceL;

       stringstream STk,MTk,LTk,STn,MTn,LTn;
        STk << pd.thickS;
        STk >> SiTkS;
        MTk << pd.thickM;
        MTk >> SiTkM;
        LTk << pd.thickL;
        LTk >> SiTkL;
        STn << pd.thinS;
        STn >> SiTnS;
        MTn << pd.thinM;
        MTn >> SiTnM;
        LTn << pd.thinL;
        LTn >> SiTnL;

       cout << right << ":" << setw(3) << Pid[x] << " : " << setw(20) << Pname[x] << " : " << setw(7) << PthickS[x] << " : " << setw(6) <<  PthinS[x]
         << " : " << setw(7) << PthickM[x] << " : " << setw(6) << PthinM[x] << " : " << setw(7) <<  PthickL[x] << " : " << setw(6) << PthinL[x]
         << " : " << setw(7) <<  PpriceS[x] << " :" << setw(8) << PpriceM[x] << " :" << setw(8) << PpriceL[x] << " :" << endl;
        x++;
    }
    cout << "+==================================================================================================================+" << endl;
    read.close();
}

int searchData()
{
    int id;
    bool checkid = false;
    do
    {
        cout << "Enter Pizza id want to search : ";
        cin >> id;
        Product pd;
        ifstream read;
        read.open("C:/ProjectPizza/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.thickS;
            read >> pd.thickM;
            read >> pd.thickL;
            read >> pd.thinS;
            read >> pd.thinM;
            read >> pd.thinL;
            read >> pd.priceS;
            read >> pd.priceM;
            read >> pd.priceL;
            if (pd.id == id)
            {
                cout << "+==================================================================================================================================+" << endl;
                cout << ": ID :         Name         : thick S : thin S : thick M : thin M : thick L : thin L : Price S : Price M : Price L : QuantityTotal :" << endl;
                cout << "+----------------------------------------------------------------------------------------------------------------------------------+" << endl;
                print(pd);
                cout << "+==================================================================================================================================+" << endl;
                return id;
                checkid = true;
            }else{
                checkid = false;
            }
        }
    } while (checkid == false);
}

void Updatedata()
{
    bool checkid = false;
    int Pids, id;

    id = searchData();
    cout << "You want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Product newData;
        cout << "Enter product name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "Enter quantity Pizzathick S : ";
        cin >> newData.thickS;
        cout << "Enter quantity Pizzathick M : ";
        cin >> newData.thickM;
        cout << "Enter quantity Pizzathick L : ";
        cin >> newData.thickL;
        cout << "Enter quantity Pizzathin S : ";
        cin >> newData.thinS;
        cout << "Enter quantity Pizzathin M : ";
        cin >> newData.thinM;
        cout << "Enter quantity Pizzathin L : ";
        cin >> newData.thinL;
        cout << "Enter Price PizzaSize S : ";
        cin >> newData.priceS;
        cout << "Enter Price PizzaSize M : ";
        cin >> newData.priceM;
        cout << "Enter Price PizzaSize L : ";
        cin >> newData.priceL;
        Product pd;
        ofstream tempFile;
        tempFile.open("C:/ProjectPizza/temp.txt");
        ifstream read;
        read.open("C:/ProjectPizza/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.thickS;
            read >> pd.thickM;
            read >> pd.thickL;
            read >> pd.thinS;
            read >> pd.thinM;
            read >> pd.thinL;
            read >> pd.priceS;
            read >> pd.priceM;
            read >> pd.priceL;
            if (pd.id != id)
            {
                tempFile << "\n" << pd.id;
                tempFile << "\n" << pd.name;
                tempFile << "\n" << pd.thickS;
                tempFile << "\n" << pd.thickM;
                tempFile << "\n" << pd.thickL;
                tempFile << "\n" << pd.thinS;
                tempFile << "\n" << pd.thinM;
                tempFile << "\n" << pd.thinL;
                tempFile << "\n" << pd.priceS;
                tempFile << "\n" << pd.priceM;
                tempFile << "\n" << pd.priceL;
            }
            else
            {
                tempFile << "\n" << pd.id;
                tempFile << "\n" << newData.name;
                tempFile << "\n" << newData.thickS;
                tempFile << "\n" << newData.thickM;
                tempFile << "\n" << newData.thickL;
                tempFile << "\n" << newData.thinS;
                tempFile << "\n" << newData.thinM;
                tempFile << "\n" << newData.thinL;
                tempFile << "\n" << newData.priceS;
                tempFile << "\n" << newData.priceM;
                tempFile << "\n" << newData.priceL;
            }
        }
        read.close();
        tempFile.close();
        remove("C:/ProjectPizza/product.txt");
        rename("C:/ProjectPizza/temp.txt", "C:/ProjectPizza/product.txt");
        cout << "Data updated successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

void deleteData()
{
    int id = searchData();
    cout << "You want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Product pd;
        ofstream tempFile;
        tempFile.open("C:/ProjectPizza/temp.txt");
        ifstream read;
        read.open("C:/ProjectPizza/product.txt");
        while (!read.eof())
        {
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.thickS;
            read >> pd.thickM;
            read >> pd.thickL;
            read >> pd.thinS;
            read >> pd.thinM;
            read >> pd.thinL;
            read >> pd.priceS;
            read >> pd.priceM;
            read >> pd.priceL;
            if (pd.id != id)
            {
                tempFile << "\n" << pd.id;
                tempFile << "\n" << pd.name;
                tempFile << "\n" << pd.thickS;
                tempFile << "\n" << pd.thickM;
                tempFile << "\n" << pd.thickL;
                tempFile << "\n" << pd.thinS;
                tempFile << "\n" << pd.thinM;
                tempFile << "\n" << pd.thinL;
                tempFile << "\n" << pd.priceS;
                tempFile << "\n" << pd.priceM;
                tempFile << "\n" << pd.priceL;
            }
        }
        read.close();
        tempFile.close();
        remove("C:/ProjectPizza/product.txt");
        rename("C:/ProjectPizza/temp.txt", "C:/ProjectPizza/product.txt");
        cout << "Data deleted successfuly" << endl;
    }
    else
    {
        cout << "Record not deleted" << endl;
    }
}

void datetime()
{
    time_t nows;

    struct tm datelc;

    nows = time(NULL);

    datelc = *localtime(&nows);

    cout << datelc.tm_mday << "/" << datelc.tm_mon + 1 << "/" << datelc.tm_year + 1900 << endl;
    cout << datelc.tm_hour << ":" << datelc.tm_min << ":" << datelc.tm_sec;
}

void Checkfile()
{
    ifstream read;
    read.open("C:/ProjectPizza/id.txt");
    if (!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID = 0;
    }
    read.close();
}

void SelectPizza(){
    Productlist();
    int slp, intid , no,intkS,intkM,intkL,intnS,intnM,intnL,intsum,intPS,intPM,intPL,Noa;
    int tkiS, tkiM, tkiL, tniS, tniM, tniL, Qt = 0,chks,quan,conselect,flour;
    string Sizes;
    bool ckp = false, cks = false,ckt = false,ckc = false;
    
        do{
            cout << "Enter Select PizzaID : ";
            cin >> slp;
            for (int i = 0; i < 100; i++){
                stringstream sw;
                sw << Pid[i];
                sw >> intid;
                if (slp == intid){
                    ckp = true;
                    no = i;
                    chks = 1;
                    break;
                }else{
                    chks = 0;
                    ckp = false;
                }
            }
            if(chks == 1){
                stringstream Stkz,Mtkz,Ltkz,Stnz,Mtnz,Ltnz;
                Stkz << PthickS[no];
                Stkz >> tkiS;
                Mtkz << PthickM[no];
                Mtkz >> tkiM;
                Ltkz << PthickL[no];
                Ltkz >> tkiL;
                Stnz << PthinS[no];
                Stnz >> tniS;
                Mtnz << PthinM[no];
                Mtnz >> tniM;
                Ltnz << PthinL[no];
                Ltnz >> tniL;


                Qt = tkiS + tkiM + tkiL + tniS + tniM + tniL;

                if(Qt == 0){
                    cout << Pname[no] <<  "Out of Stock" << endl;
                    ckp = false;
                }
            }
            } while (ckp == false);
            int chh = 0;
            do{
            if(chh == 1){
                Productlist();
            }
            cout << "1.flour thick" << endl;
            cout << "2.flour thin" << endl;
            cout << "Enter flour : ";
            cin >> flour;
            cout << "Enter (S/M/L) Size Pizza : ";
            cin >> Sizes;
            if(Sizes == "S" && flour == 1){
                if(PthickS[no] == "0"){
                    cout << Pname[no] << " flour thick S Out of Stock" << endl;
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "M" && flour == 1){
                if(PthickM[no] == "0"){
                    cout << Pname[no] << " flour thick M Out of Stock" << endl;
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "L" && flour == 1){
                if(PthickL[no] == "0"){
                    cout << Pname[no] << " flour thick L Out of Stock" << endl;
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "S" && flour == 2){
                if(PthinS[no] == "0"){
                    cout << Pname[no] << " flour thin S Out of Stock" << endl;
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "M" && flour == 2){
                if(PthinM[no] == "0"){
                    cout << Pname[no] << " flour thin M Out of Stock" << endl;
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "L" && flour == 2){
                if(PthinL[no] == "0"){
                    cout << Pname[no] << " flour thin L Out of Stock" << endl;
                    cks = false;
                }else{
                    cks = true;
                }
            }else{
                chh = 1;
                cks = false;
                system("CLS");
            }
        } while (cks == false);

        do
        {
            stringstream Itks,Itkm,Itkl,Itns,Itnm,Itnl;
            Itks << PthickS[no];
            Itks >> intkS;
            Itkm << PthickM[no];
            Itkm >> intkM;
            Itkl << PthickL[no];
            Itkl >> intkL;
            Itns << PthinS[no];
            Itns >> intnS;
            Itnm << PthinM[no];
            Itnm >> intnM;
            Itnl << PthinL[no];
            Itnl >> intnL;
            
            cout << "Enter Quantity : ";
            cin >> quan;
            if(Sizes == "S" && flour == 1){
                if(quan > 0 && quan <= intkS){
                    ckt = true;
                }else{
                    ckt = false;
                }
            }else if(Sizes == "M" && flour == 1){
                if(quan > 0 && quan <= intkM){
                    ckt = true;
                }else{
                    ckt = false;
                }
            }else if(Sizes == "L" && flour == 1){
                if(quan > 0 && quan <= intkL){
                    ckt = true;
                }else{
                    ckt = false;
                }
            }else if(Sizes == "S" && flour == 2){
                if(quan > 0 && quan <= intnS){
                    ckt = true;
                }else{
                    ckt = false;
                }
            }
            else if(Sizes == "M" && flour == 2){
                if(quan > 0 && quan <= intnM){
                    ckt = true;
                }else{
                    ckt = false;
                }
            }
            else if(Sizes == "L" && flour == 2){
                if(quan > 0 && quan <= intnL){
                    ckt = true;
                }else{
                    ckt = false;
                }
            }
        } while (ckt == false);

        // cout << Cnum;
        int checko = 0;

        for (int g = 0; g < 3; g++)
        {
            if(Oid[g] == slp){
                if(Ofour[g] == flour && Osize[g] == Sizes){
                    checko = 1;
                    break;
                }else{
                    checko = 0;
                }
            }
        }

        int intPPS,intPPM,intPPL,sumto = 0,sumtotal = 0;
        
        stringstream PPs,PPm,PPl;
        PPs << PpriceS[no];
        PPs >> intPPS;
        PPm << PpriceM[no];
        PPm >> intPPM;
        PPl << PpriceL[no];
        PPl >> intPPL;

        if(checko == 0){
            if(Sizes == "S"){
                sumto = intPPS;
            }else if(Sizes == "M"){
                sumto = intPPM;
            }else if(Sizes == "L"){
                sumto = intPPL;
            }

            Oid[Cnum] = slp;
            Ofour[Cnum] = flour;
            Osize[Cnum] = Sizes;
            Oquan[Cnum] = quan;
            Ono[Cnum] = no;
            // Osum[Cnum] = quan * sumto;
        }else{
            Cnum -= 1;
            system("CLS");
            cout << "+-----------------------------------+" << endl;
            cout << "+Repeat Order >> new pizza selection+" << endl;
            cout << "+-----------------------------------+" << endl;
        }
}

void vieworder(){
    int intsum,intPS,intPM,intPL,Noa,Totalsums = 0;
    string fours;
    bool ckc = false;

    cout << "+==================================================================+" << endl;
    cout << ": No :         Name         : flour : Size : Quantity : TotalPrice :" << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    for (int k = 0; k < 3; k++)
    {
        Noa = Ono[k];

        stringstream Ps,Pm,Pl;
        Ps << PpriceS[Noa];
        Ps >> intPS;
        Pm << PpriceM[Noa];
        Pm >> intPM;
        Pl << PpriceL[Noa];
        Pl >> intPL;

        if(Osize[k] == "S"){
            intsum = intPS;
        }else if(Osize[k] == "M"){
            intsum = intPM;
        }else if(Osize[k] == "L"){
            intsum = intPL;
        }
        
        if(Ofour[k] == 1){
            fours = "Thick";
        }else{
            fours = "Thin";
        }

        if(Osize[k] != "\0"){
            Totalsums = Totalsums +  (Oquan[k] * intsum);

            cout << right << ":" << setw(3) << k + 1 << " : " << setw(20) << Pname[Noa] << " : " << setw(5) << fours << " : " << setw(4)
            << Osize[k] << " : " << setw(8) << Oquan[k] << " : " << setw(10) << Oquan[k] * intsum  << " : " << endl ;
        }
    }
    cout << "+==================================================================+" << endl;
    cout << right << setw(53) << "Total" << " :" << setw(11) << Totalsums << endl;
    cout << "+==================================================================+" << endl;

    // SSumtotal = Totalsums;
}

void Cancelorder(){
    Cnum = 0;
    SSumtotal = 0;
    for (int i = 0; i < 3; i++)
    {
        Oid[i] = {};
        Ofour[i] = {};
        Osize[i] = "";
        Oquan[i] = {};
        Ono[i] = {};
        // Osum[i] = {};
    }
}

void updateOrder(){
    int i,iS,iM,iL,nS,nM,nL,Oid1,Oid2,Oid3,Quanli1,Quanli2,Quanli3,flour1,flour2,flour3;
    string SizeE1,SizeE2,SizeE3;
    i = 0;
   
    Oid1 = Oid[0];
    Oid2 = Oid[1];
    Oid3 = Oid[2];
    Quanli1 = Oquan[0];
    Quanli2 = Oquan[1];
    Quanli3 = Oquan[2];
    flour1 = Ofour[0];
    flour2 = Ofour[1];
    flour1 = Ofour[2];
    SizeE1 = Osize[0];
    SizeE2 = Osize[1];
    SizeE3 = Osize[2];
   
    if(Oid1 != 0){
        Product pd;
        ofstream tempFile;
        tempFile.open("C:/ProjectPizza/temp.txt");
        ifstream read;
        read.open("C:/ProjectPizza/product.txt");
        while (!read.eof()){
            read >> pd.id;
            read.ignore();
            getline(read, pd.name);
            read >> pd.thickS;
            read >> pd.thickM;
            read >> pd.thickL;
            read >> pd.thinS;
            read >> pd.thinM;
            read >> pd.thinL;
            read >> pd.priceS;
            read >> pd.priceM;
            read >> pd.priceL;
            if (pd.id == Oid1){
                if(Ofour[0] == 1 && Osize[0] == "S"){
                    stringstream tcS;
                    tcS << pd.thickS;
                    tcS >> iS;
                    tempFile << "\n" << pd.id;
                    tempFile << "\n" << pd.name;
                    tempFile << "\n" << iS - Quanli1;
                    tempFile << "\n" << pd.thickM;
                    tempFile << "\n" << pd.thickL;
                    tempFile << "\n" << pd.thinS;
                    tempFile << "\n" << pd.thinM;
                    tempFile << "\n" << pd.thinL;
                    tempFile << "\n" << pd.priceS;
                    tempFile << "\n" << pd.priceM;
                    tempFile << "\n" << pd.priceL;
                }else if(Ofour[0] == 1 && Osize[0] == "M"){
                    stringstream tcM;
                    tcM << pd.thickM;
                    tcM >> iM;
                    tempFile << "\n" << pd.id;
                    tempFile << "\n" << pd.name;
                    tempFile << "\n" << pd.thickS;
                    tempFile << "\n" << iM - Quanli1;
                    tempFile << "\n" << pd.thickL;
                    tempFile << "\n" << pd.thinS;
                    tempFile << "\n" << pd.thinM;
                    tempFile << "\n" << pd.thinL;
                    tempFile << "\n" << pd.priceS;
                    tempFile << "\n" << pd.priceM;
                    tempFile << "\n" << pd.priceL;
                }else if(Ofour[0] == 1 && Osize[0] == "L"){
                    stringstream tcL;
                    tcL << pd.thickL;
                    tcL >> iL;
                    tempFile << "\n" << pd.id;
                    tempFile << "\n" << pd.name;
                    tempFile << "\n" << pd.thickS;
                    tempFile << "\n" << pd.thickM;
                    tempFile << "\n" << iL - Quanli1;
                    tempFile << "\n" << pd.thinS;
                    tempFile << "\n" << pd.thinM;
                    tempFile << "\n" << pd.thinL;
                    tempFile << "\n" << pd.priceS;
                    tempFile << "\n" << pd.priceM;
                    tempFile << "\n" << pd.priceL;
                }else if(Ofour[0] == 2 && Osize[0] == "S"){
                    stringstream tnS;
                    tnS << pd.thinS;
                    tnS >> nS;
                    tempFile << "\n" << pd.id;
                    tempFile << "\n" << pd.name;
                    tempFile << "\n" << pd.thickS;
                    tempFile << "\n" << pd.thickM;
                    tempFile << "\n" << pd.thickL;
                    tempFile << "\n" << nS - Quanli1;
                    tempFile << "\n" << pd.thinM;
                    tempFile << "\n" << pd.thinL;
                    tempFile << "\n" << pd.priceS;
                    tempFile << "\n" << pd.priceM;
                    tempFile << "\n" << pd.priceL;
                }else if(Ofour[0] == 2 && Osize[0] == "M"){
                    stringstream tnM;
                    tnM << pd.thinM;
                    tnM >> nM;
                    tempFile << "\n" << pd.id;
                    tempFile << "\n" << pd.name;
                    tempFile << "\n" << pd.thickS;
                    tempFile << "\n" << pd.thickM;
                    tempFile << "\n" << pd.thickL;
                    tempFile << "\n" << pd.thinS;
                    tempFile << "\n" << nM - Quanli1;
                    tempFile << "\n" << pd.thinL;
                    tempFile << "\n" << pd.priceS;
                    tempFile << "\n" << pd.priceM;
                    tempFile << "\n" << pd.priceL;
                }else if(Ofour[0] == 2 && Osize[0] == "L"){
                    stringstream tnL;
                    tnL << pd.thinL;
                    tnL >> nL;
                    tempFile << "\n" << pd.id;
                    tempFile << "\n" << pd.name;
                    tempFile << "\n" << pd.thickS;
                    tempFile << "\n" << pd.thickM;
                    tempFile << "\n" << pd.thickL;
                    tempFile << "\n" << pd.thinS;
                    tempFile << "\n" << pd.thinM;
                    tempFile << "\n" << nL - Quanli1;
                    tempFile << "\n" << pd.priceS;
                    tempFile << "\n" << pd.priceM;
                    tempFile << "\n" << pd.priceL;
                }
            }else{
                tempFile << "\n" << pd.id;
                tempFile << "\n" << pd.name;
                tempFile << "\n" << pd.thickS;
                tempFile << "\n" << pd.thickM;
                tempFile << "\n" << pd.thickL;
                tempFile << "\n" << pd.thinS;
                tempFile << "\n" << pd.thinM;
                tempFile << "\n" << pd.thinL;
                tempFile << "\n" << pd.priceS;
                tempFile << "\n" << pd.priceM;
                tempFile << "\n" << pd.priceL;
                }
            }
        read.close();
        tempFile.close();
        remove("C:/ProjectPizza/product.txt");
        rename("C:/ProjectPizza/temp.txt", "C:/ProjectPizza/product.txt");
        cout << "Data updated successfuly" << endl;
    }
    if(Oid2 != 0){
        Product pd2;
        ofstream tempFile2;
        tempFile2.open("C:/ProjectPizza/temp.txt");
        ifstream read2;
        read2.open("C:/ProjectPizza/product.txt");
        while (!read2.eof()){
            read2 >> pd2.id;
            read2.ignore();
            getline(read2, pd2.name);
            read2 >> pd2.thickS;
            read2 >> pd2.thickM;
            read2 >> pd2.thickL;
            read2 >> pd2.thinS;
            read2 >> pd2.thinM;
            read2 >> pd2.thinL;
            read2 >> pd2.priceS;
            read2 >> pd2.priceM;
            read2 >> pd2.priceL;
            if (pd2.id == Oid2){
                if(Ofour[1] == 1 && Osize[1] == "S"){
                    stringstream tcS;
                    tcS << pd2.thickS;
                    tcS >> iS;
                    tempFile2 << "\n" << pd2.id;
                    tempFile2 << "\n" << pd2.name;
                    tempFile2 << "\n" << iS - Quanli1;
                    tempFile2 << "\n" << pd2.thickM;
                    tempFile2 << "\n" << pd2.thickL;
                    tempFile2 << "\n" << pd2.thinS;
                    tempFile2 << "\n" << pd2.thinM;
                    tempFile2 << "\n" << pd2.thinL;
                    tempFile2 << "\n" << pd2.priceS;
                    tempFile2 << "\n" << pd2.priceM;
                    tempFile2 << "\n" << pd2.priceL;
                }else if(Ofour[1] == 1 && Osize[1] == "M"){
                    stringstream tcM;
                    tcM << pd2.thickM;
                    tcM >> iM;
                    tempFile2 << "\n" << pd2.id;
                    tempFile2 << "\n" << pd2.name;
                    tempFile2 << "\n" << pd2.thickS;
                    tempFile2 << "\n" << iM - Quanli1;
                    tempFile2 << "\n" << pd2.thickL;
                    tempFile2 << "\n" << pd2.thinS;
                    tempFile2 << "\n" << pd2.thinM;
                    tempFile2 << "\n" << pd2.thinL;
                    tempFile2 << "\n" << pd2.priceS;
                    tempFile2 << "\n" << pd2.priceM;
                    tempFile2 << "\n" << pd2.priceL;
                }else if(Ofour[1] == 1 && Osize[1] == "L"){
                    stringstream tcL;
                    tcL << pd2.thickL;
                    tcL >> iL;
                    tempFile2 << "\n" << pd2.id;
                    tempFile2 << "\n" << pd2.name;
                    tempFile2 << "\n" << pd2.thickS;
                    tempFile2 << "\n" << pd2.thickM;
                    tempFile2 << "\n" << iL - Quanli1;
                    tempFile2 << "\n" << pd2.thinS;
                    tempFile2 << "\n" << pd2.thinM;
                    tempFile2 << "\n" << pd2.thinL;
                    tempFile2 << "\n" << pd2.priceS;
                    tempFile2 << "\n" << pd2.priceM;
                    tempFile2 << "\n" << pd2.priceL;
                }else if(Ofour[1] == 2 && Osize[1] == "S"){
                    stringstream tnS;
                    tnS << pd2.thinS;
                    tnS >> nS;
                    tempFile2 << "\n" << pd2.id;
                    tempFile2 << "\n" << pd2.name;
                    tempFile2 << "\n" << pd2.thickS;
                    tempFile2 << "\n" << pd2.thickM;
                    tempFile2 << "\n" << pd2.thickL;
                    tempFile2 << "\n" << nS - Quanli1;
                    tempFile2 << "\n" << pd2.thinM;
                    tempFile2 << "\n" << pd2.thinL;
                    tempFile2 << "\n" << pd2.priceS;
                    tempFile2 << "\n" << pd2.priceM;
                    tempFile2 << "\n" << pd2.priceL;
                }else if(Ofour[1] == 2 && Osize[1] == "M"){
                    stringstream tnM;
                    tnM << pd2.thinM;
                    tnM >> nM;
                    tempFile2 << "\n" << pd2.id;
                    tempFile2 << "\n" << pd2.name;
                    tempFile2 << "\n" << pd2.thickS;
                    tempFile2 << "\n" << pd2.thickM;
                    tempFile2 << "\n" << pd2.thickL;
                    tempFile2 << "\n" << pd2.thinS;
                    tempFile2 << "\n" << nM - Quanli1;
                    tempFile2 << "\n" << pd2.thinL;
                    tempFile2 << "\n" << pd2.priceS;
                    tempFile2 << "\n" << pd2.priceM;
                    tempFile2 << "\n" << pd2.priceL;
                }else if(Ofour[1] == 2 && Osize[1] == "L"){
                    stringstream tnL;
                    tnL << pd2.thinL;
                    tnL >> nL;
                    tempFile2 << "\n" << pd2.id;
                    tempFile2 << "\n" << pd2.name;
                    tempFile2 << "\n" << pd2.thickS;
                    tempFile2 << "\n" << pd2.thickM;
                    tempFile2 << "\n" << pd2.thickL;
                    tempFile2 << "\n" << pd2.thinS;
                    tempFile2 << "\n" << pd2.thinM;
                    tempFile2 << "\n" << nL - Quanli1;
                    tempFile2 << "\n" << pd2.priceS;
                    tempFile2 << "\n" << pd2.priceM;
                    tempFile2 << "\n" << pd2.priceL;
                }
            }else{
                tempFile2 << "\n" << pd2.id;
                tempFile2 << "\n" << pd2.name;
                tempFile2 << "\n" << pd2.thickS;
                tempFile2 << "\n" << pd2.thickM;
                tempFile2 << "\n" << pd2.thickL;
                tempFile2 << "\n" << pd2.thinS;
                tempFile2 << "\n" << pd2.thinM;
                tempFile2 << "\n" << pd2.thinL;
                tempFile2 << "\n" << pd2.priceS;
                tempFile2 << "\n" << pd2.priceM;
                tempFile2 << "\n" << pd2.priceL;
                }
            }
        read2.close();
        tempFile2.close();
        remove("C:/ProjectPizza/product.txt");
        rename("C:/ProjectPizza/temp.txt", "C:/ProjectPizza/product.txt");
        cout << "Data updated successfuly" << endl;
    }

    if(Oid3 != 0){
        Product pd3;
        ofstream tempFile3;
        tempFile3.open("C:/ProjectPizza/temp.txt");
        ifstream read3;
        read3.open("C:/ProjectPizza/product.txt");
        while (!read3.eof()){
            read3 >> pd3.id;
            read3.ignore();
            getline(read3, pd3.name);
            read3 >> pd3.thickS;
            read3 >> pd3.thickM;
            read3 >> pd3.thickL;
            read3 >> pd3.thinS;
            read3 >> pd3.thinM;
            read3 >> pd3.thinL;
            read3 >> pd3.priceS;
            read3 >> pd3.priceM;
            read3 >> pd3.priceL;
            if (pd3.id == Oid3){
                if(Ofour[1] == 1 && Osize[1] == "S"){
                    stringstream tcS;
                    tcS << pd3.thickS;
                    tcS >> iS;
                    tempFile3 << "\n" << pd3.id;
                    tempFile3 << "\n" << pd3.name;
                    tempFile3 << "\n" << iS - Quanli1;
                    tempFile3 << "\n" << pd3.thickM;
                    tempFile3 << "\n" << pd3.thickL;
                    tempFile3 << "\n" << pd3.thinS;
                    tempFile3 << "\n" << pd3.thinM;
                    tempFile3 << "\n" << pd3.thinL;
                    tempFile3 << "\n" << pd3.priceS;
                    tempFile3 << "\n" << pd3.priceM;
                    tempFile3 << "\n" << pd3.priceL;
                }else if(Ofour[1] == 1 && Osize[1] == "M"){
                    stringstream tcM;
                    tcM << pd3.thickM;
                    tcM >> iM;
                    tempFile3 << "\n" << pd3.id;
                    tempFile3 << "\n" << pd3.name;
                    tempFile3 << "\n" << pd3.thickS;
                    tempFile3 << "\n" << iM - Quanli1;
                    tempFile3 << "\n" << pd3.thickL;
                    tempFile3 << "\n" << pd3.thinS;
                    tempFile3 << "\n" << pd3.thinM;
                    tempFile3 << "\n" << pd3.thinL;
                    tempFile3 << "\n" << pd3.priceS;
                    tempFile3 << "\n" << pd3.priceM;
                    tempFile3 << "\n" << pd3.priceL;
                }else if(Ofour[1] == 1 && Osize[1] == "L"){
                    stringstream tcL;
                    tcL << pd3.thickL;
                    tcL >> iL;
                    tempFile3 << "\n" << pd3.id;
                    tempFile3 << "\n" << pd3.name;
                    tempFile3 << "\n" << pd3.thickS;
                    tempFile3 << "\n" << pd3.thickM;
                    tempFile3 << "\n" << iL - Quanli1;
                    tempFile3 << "\n" << pd3.thinS;
                    tempFile3 << "\n" << pd3.thinM;
                    tempFile3 << "\n" << pd3.thinL;
                    tempFile3 << "\n" << pd3.priceS;
                    tempFile3 << "\n" << pd3.priceM;
                    tempFile3 << "\n" << pd3.priceL;
                }else if(Ofour[1] == 2 && Osize[1] == "S"){
                    stringstream tnS;
                    tnS << pd3.thinS;
                    tnS >> nS;
                    tempFile3 << "\n" << pd3.id;
                    tempFile3 << "\n" << pd3.name;
                    tempFile3 << "\n" << pd3.thickS;
                    tempFile3 << "\n" << pd3.thickM;
                    tempFile3 << "\n" << pd3.thickL;
                    tempFile3 << "\n" << nS - Quanli1;
                    tempFile3 << "\n" << pd3.thinM;
                    tempFile3 << "\n" << pd3.thinL;
                    tempFile3 << "\n" << pd3.priceS;
                    tempFile3 << "\n" << pd3.priceM;
                    tempFile3 << "\n" << pd3.priceL;
                }else if(Ofour[1] == 2 && Osize[1] == "M"){
                    stringstream tnM;
                    tnM << pd3.thinM;
                    tnM >> nM;
                    tempFile3 << "\n" << pd3.id;
                    tempFile3 << "\n" << pd3.name;
                    tempFile3 << "\n" << pd3.thickS;
                    tempFile3 << "\n" << pd3.thickM;
                    tempFile3 << "\n" << pd3.thickL;
                    tempFile3 << "\n" << pd3.thinS;
                    tempFile3 << "\n" << nM - Quanli1;
                    tempFile3 << "\n" << pd3.thinL;
                    tempFile3 << "\n" << pd3.priceS;
                    tempFile3 << "\n" << pd3.priceM;
                    tempFile3 << "\n" << pd3.priceL;
                }else if(Ofour[1] == 2 && Osize[1] == "L"){
                    stringstream tnL;
                    tnL << pd3.thinL;
                    tnL >> nL;
                    tempFile3 << "\n" << pd3.id;
                    tempFile3 << "\n" << pd3.name;
                    tempFile3 << "\n" << pd3.thickS;
                    tempFile3 << "\n" << pd3.thickM;
                    tempFile3 << "\n" << pd3.thickL;
                    tempFile3 << "\n" << pd3.thinS;
                    tempFile3 << "\n" << pd3.thinM;
                    tempFile3 << "\n" << nL - Quanli1;
                    tempFile3 << "\n" << pd3.priceS;
                    tempFile3 << "\n" << pd3.priceM;
                    tempFile3 << "\n" << pd3.priceL;
                }
            }else{
                tempFile3 << "\n" << pd3.id;
                tempFile3 << "\n" << pd3.name;
                tempFile3 << "\n" << pd3.thickS;
                tempFile3 << "\n" << pd3.thickM;
                tempFile3 << "\n" << pd3.thickL;
                tempFile3 << "\n" << pd3.thinS;
                tempFile3 << "\n" << pd3.thinM;
                tempFile3 << "\n" << pd3.thinL;
                tempFile3 << "\n" << pd3.priceS;
                tempFile3 << "\n" << pd3.priceM;
                tempFile3 << "\n" << pd3.priceL;
                }
            }
        read3.close();
        tempFile3.close();
        remove("C:/ProjectPizza/product.txt");
        rename("C:/ProjectPizza/temp.txt", "C:/ProjectPizza/product.txt");
        cout << "Data updated successfuly" << endl;
    }
}

void Confirmorder(){
    string timesorder,strmin,strsec,strhour;
    int intssum,intPSS,intPMM,intPLL,Noa,Totalsumss = 0;
    time_t nows;
    int money,balanc = 0;

    struct tm datelc;

    for (int k = 0; k < 3; k++){
        Noa = Ono[k];

        stringstream Pss,Pmm,Pll;
        Pss << PpriceS[Noa];
        Pss >> intPSS;
        Pmm << PpriceM[Noa];
        Pmm >> intPMM;
        Pll << PpriceL[Noa];
        Pll >> intPLL;

        if(Osize[k] == "S"){
            intssum = intPSS;
        }else if(Osize[k] == "M"){
            intssum = intPMM;
        }else if(Osize[k] == "L"){
            intssum = intPLL;
        }
        if(Osize[k] != "\0"){
            Totalsumss = Totalsumss +  (Oquan[k] * intssum);
        }
    }
    do{
        cout << ": ============================================== :" << endl;
        cout << right << ": amount to be paid : " << setw(21) << Totalsumss << " Baht" << endl;
        cout << ": Enter Money : "<< setw(22) << " ";
        cin >> money;
    } while (money < Totalsumss);
        balanc = money - Totalsumss;
        cout << right << ": give the change :" << setw(25)  << balanc << " Baht" << endl ;
        cout << ":                                                :" << endl;
        cout << ": ______________________________________________ :" << endl;
        system("pause");
        
    nows = time(NULL);
    datelc = *localtime(&nows);
    ifstream read;
    read.open("C:/ProjectPizza/orderid.txt");
    if (!read.fail()){
        read >> OrderID;
    }else{
        OrderID = 0;
    }
    OrderID++;
    read.close();
    ofstream write;
    write.open("C:/ProjectPizza/order.txt", ios::app);
    write << "\n" << OrderID;
    write << "\n" << Cnum + 1;
    for (int i = 0; i < Cnum + 1; i++){
        write << "\n" << Oid[i];
        write << "\n" << Ofour[i];
        write << "\n" << Osize[i];
        write << "\n" << Oquan[i];
    }
    write << "\n" << Totalsumss;
    write << "\n" << datelc.tm_wday;
    write << "\n" << datelc.tm_mday;
    write << "\n" << datelc.tm_mon + 1;
    write << "\n" << datelc.tm_year + 1900;
    write << "\n" << datelc.tm_hour << ":" << datelc.tm_min << ":" << datelc.tm_sec;
    write.close();
    write.open("C:/ProjectPizza/orderid.txt");
    write << OrderID;
    write.close();
    cout << "Data save to file" << endl;
    updateOrder();
    Cancelorder();
}

void Pizza()
{
    int conselect;
    char can, con;
    SelectPizza();
    bool ckc = false;
    do{
        if(Cnum == 2){
            cout << "1.ViewOrder" << endl;
            cout << "2.CancelOrder" << endl;
            cout << "3.ConfirmOrder" << endl;
            cout << "Enter Select : ";
            cin >> conselect;
            if(conselect == 1){
        vieworder();
            }else if(conselect == 2){
                cout << "Enter (y/n) ";
                cin >> can;
                if(can == 'y'){
                    system("CLS");
                    Cancelorder();
                    ckc = true;
                }else{
                    ckc = false;
                }
            }else if(conselect == 3){
                cout << "Enter (y/n) ";
                cin >> con;
                if(con == 'y'){
                    system("CLS");
                    Confirmorder();
                    ckc = true;
                }else{
                    ckc = false;
                }
            }else{
                ckc = false;
            }
        }else{
            cout << "1.Select Next Pizza" << endl;
            cout << "2.ViewOrder" << endl;
            cout << "3.CancelOrder" << endl;
            cout << "4.ConfirmOrder" << endl;
            cout << "Enter Select : ";
            cin >> conselect;
            if(conselect == 1){
                Cnum += 1;
                system("CLS");
                SelectPizza();
            }else if(conselect == 2){
                system("CLS");
                vieworder();
            }else if(conselect == 3){
                cout << "Enter (y/n) ";
                cin >> can;
                if(can == 'y'){
                    system("CLS");
                    Cancelorder();
                    ckc = true;
                }else{
                    ckc = false;
                }
            }else if(conselect == 4){
                cout << "Enter (y/n) ";
                cin >> con;
                if(con == 'y'){
                    system("CLS");
                    Confirmorder();
                    ckc = true;
                }else{
                    ckc = false;
                }
            }
        }
    } while (ckc == false);
}

void vieworderlist(){
    int Onum,inum;
    string cflour;
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    ifstream reads;
    reads.open("C:/ProjectPizza/product.txt");
    int x = 0;

    while (!reads.eof())
    {
        string strid;

        reads >> pd.id;
        reads.ignore();
        getline(reads, pd.name);
        reads >> pd.thickS;
        reads >> pd.thickM;
        reads >> pd.thickL;
        reads >> pd.thinS;
        reads >> pd.thinM;
        reads >> pd.thinL;
        reads >> pd.priceS;
        reads >> pd.priceM;
        reads >> pd.priceL;

        strid = to_string(pd.id);

        Pid[x] = strid;
        Pname[x] = pd.name;
        PthickS[x] = pd.thickS;
        PthickM[x] = pd.thickM;
        PthickL[x] = pd.thickL;
        PthinS[x] = pd.thinS;
        PthinM[x] = pd.thinM;
        PthinL[x] = pd.thinL;
        PpriceS[x] = pd.priceS;
        PpriceM[x] = pd.priceM;
        PpriceL[x] = pd.priceL;
        x++;
    }
    reads.close();
    Orders O;
    ifstream read;
    read.open("C:/ProjectPizza/order.txt");
    while (!read.eof())
    {
        read >> O.OrderIds;
        read >> O.OrderQl;
        if(O.OrderQl != 0){
            if(O.OrderQl == 1){
                Onum = 1;
            }else if(O.OrderQl == 2){
                Onum = 2;
            }else if(O.OrderQl == 3){
                Onum = 3;
            }
            cout << "=================================================================" << endl;
            cout << "Order ID " << O.OrderIds << endl;
            cout << "=================================================================" << endl;
            cout << ":           Name            |  Flour  | Size | Quanlity | Price :" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for (int i = 1; i <= Onum; i++)
            {
                read >> O.OrderPid;
                read >> O.Orderflour;
                read >> O.OrderSize;
                read >> O.OrderQ;

                if(O.Orderflour == 1){
                    cflour = "Thick";
                }else{
                    cflour = "Thin";
                }
                int ccnum = 0,PricePz = 0,pris,prim,pril;
                string strid,strname;
                strid = to_string(O.OrderPid);
                for (int j = 0; j < 100; j++)
                {
                if(strid == Pid[j]){
                    strname = Pname[j];

                    stringstream rps,rpm,rpl;
                    rps << PpriceS[j];
                    rps >> pris;
                    rpm << PpriceM[j];
                    rpm >> prim;
                    rpl << PpriceL[j];
                    rpl >> pril;

                    if(O.OrderSize == "S"){
                        PricePz = pris;
                    }else if(O.OrderSize == "M"){
                        PricePz = prim;
                    }else if(O.OrderSize == "L"){
                        PricePz = pril;
                    }
                    break;
                }
                }
                cout << "  " << right << setw(23) << strname << setw(4) << "|" << setw(7) 
                << cflour << "  |" << setw(4) << O.OrderSize << "  |" << setw(5) << O.OrderQ << setw(6) << "  |" << setw(5) << O.OrderQ * PricePz << setw(2) << "  |" << endl;
            }
            cout << "-----------------------------------------------------------------" << endl;

            read >> O.OrderTT;
            read >> O.Orderwday;
            read >> O.Orderday;
            read >> O.Ordermount;
            read >> O.Orderyear;
            read >> O.Ordertime;
            string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
            string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
            int m = O.Ordermount - 1;
            int d = O.Orderwday;
                cout << right << setw(32) << " Total " << O.OrderTT << " Baht"<< endl;
                cout << right << setw(20) << day[d] << "  " << O.Orderday << "  " << month[m] << "  " << O.Orderyear << "  " << O.Ordertime << endl;
            cout << "-----------------------------------------------------------------" << endl <<endl;
        }else{
            cout << "No data" << endl;
        }
    }
    read.close();
}

void ViewRePortDay(){
    int Onum,Onums,inum,Sumttto = 0;
    string cflour,dayss;
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    int OD,OM,OY,CWD,CD,CM,CY,checkvalue;
    string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int OsQl[200] = {},OsPid[200][200] = {},Osflour[200][200] = {}, OsQ[200][200] = {},Osday[200] = {},Osmonth[200] = {},Osyear[200] = {},Oswday[200] = {},OsTT[200] = {};
    string Ossize[200][200] = {},OsId[200] = {};
    string stridss;
    int x = 0;
    int k = 0;
    ifstream reads;
    reads.open("C:/ProjectPizza/product.txt");
    while (!reads.eof())
    {
        string strid;

        reads >> pd.id;
        reads.ignore();
        getline(reads, pd.name);
        reads >> pd.thickS;
        reads >> pd.thickM;
        reads >> pd.thickL;
        reads >> pd.thinS;
        reads >> pd.thinM;
        reads >> pd.thinL;
        reads >> pd.priceS;
        reads >> pd.priceM;
        reads >> pd.priceL;

        strid = to_string(pd.id);

        Pid[x] = strid;
        Pname[x] = pd.name;
        PthickS[x] = pd.thickS;
        PthickM[x] = pd.thickM;
        PthickL[x] = pd.thickL;
        PthinS[x] = pd.thinS;
        PthinM[x] = pd.thinM;
        PthinL[x] = pd.thinL;
        PpriceS[x] = pd.priceS;
        PpriceM[x] = pd.priceM;
        PpriceL[x] = pd.priceL;
        x++;
    }
    reads.close();
    cout << "Enter Day : ";
    cin >> OD;
    cout << "Enter Month : ";
    cin >> OM;
    cout << "Enter Year : ";
    cin >> OY;
    Orders O;
    ifstream read;
    read.open("C:/ProjectPizza/order.txt");
    while (!read.eof())
    {
        read >> O.OrderIds;
        read >> O.OrderQl;
        if(O.OrderQl == 1){
            Onum = 1;
        }else if(O.OrderQl == 2){
            Onum = 2;
        }else if(O.OrderQl == 3){
            Onum = 3;
        }
        for (int i = 0; i < Onum; i++)
        {
            read >> O.OrderPid;
            read >> O.Orderflour;
            read >> O.OrderSize;
            read >> O.OrderQ;

            OsPid[k][i] = O.OrderPid;
            Osflour[k][i] = O.Orderflour;
            Ossize[k][i] = O.OrderSize;
            OsQ[k][i] = O.OrderQ;
        }
        read >> O.OrderTT;
        read >> O.Orderwday;
        read >> O.Orderday;
        read >> O.Ordermount;
        read >> O.Orderyear;
        read >> O.Ordertime;
        int m = O.Ordermount - 1;
        int d = O.Orderwday;

        stridss = to_string(O.OrderIds);
        
        OsId[k] = stridss;
        OsQl[k] = O.OrderQl;
        Osday[k] = O.Orderday;
        Osmonth[k] = O.Ordermount;
        Osyear[k] = O.Orderyear;
        Oswday[k] = O.Orderwday;
        OsTT[k] = O.OrderTT;

        
        if(O.Orderday == OD && O.Ordermount == OM && O.Orderyear == OY){
            Sumttto = Sumttto + O.OrderTT;
            CWD = O.Orderwday;
            CD = O.Orderday;
            CM = O.Ordermount - 1;
            CY = O.Orderyear;
        }
        k++;
    }
    read.close();

    if(Sumttto == 0){
        cout << "Not! Data" << endl;
    }else{
        string strnames,strpid,strflour;
        int pris,prim,pril,PricePz = 0;

        for (int y = 0; y < 200; y++)
        {
            if(OsId[y] != "\0"){
                if(Osday[y] == OD && Osmonth[y] == OM && Osyear[y] == OY){
                cout << "=================================================================" << endl;
                cout << "Order ID " << OsId[y] << endl;
                cout << "=================================================================" << endl;
                cout << ":           Name            |  Flour  | Size | Quanlity | Price :" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                    for (int j = 0; j <= OsQl[j]; j++)
                    {
                        for (int v = 0; v < 200; v++)
                        {
                        strpid = to_string(OsPid[y][j]);
                            if(strpid == Pid[v]){
                                strnames = Pname[v];

                                stringstream rps,rpm,rpl;
                                rps << PpriceS[v];
                                rps >> pris;
                                rpm << PpriceM[v];
                                rpm >> prim;
                                rpl << PpriceL[v];
                                rpl >> pril;
                                break;
                            }
                        }
                        if(OsPid[y][j] != 0){
                            if(Osflour[y][j] == 1){
                                strflour = "Thick";
                            }else{
                                strflour = "Thin";
                            }
                            if(Ossize[y][j] == "S"){
                                PricePz = pris;
                            }else if(Ossize[y][j] == "M"){
                                PricePz = prim;
                            }else if(Ossize[y][j] == "L"){
                                PricePz = pril;
                            }
                            cout << "  " << right << setw(23) << strnames << setw(4) << "|" << setw(7) 
                            << strflour << "  |" << setw(4) << Ossize[y][j] << "  |" << setw(5) << OsQ[y][j] << setw(6) 
                            << "  |" << setw(5) << OsQ[y][j] * PricePz << setw(2) << "  |" << endl;
                        }
                    }
                    cout << "-----------------------------------------------------------------" << endl;
                    cout << right << setw(32) << " Total " << OsTT[y] << " Baht"<< endl;
                    cout << "-----------------------------------------------------------------" << endl <<endl;
                }
            }
        }
        cout << day[CWD] << " " << CD << " " << month[CM] << " " << CY << endl;
        cout << "Total " << Sumttto << endl << endl;
    }
}

void ViewRePortMonth(){
     int Onum,Onums,inum,Sumttto = 0;
    string cflour,dayss;
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    int OD,OM,OY,CWD,CD,CM,CY,checkvalue;
    string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int OsQl[200] = {},OsPid[200][200] = {},Osflour[200][200] = {}, OsQ[200][200] = {},Osday[200] = {},Osmonth[200] = {},Osyear[200] = {},Oswday[200] = {},OsTT[200] = {};
    string Ossize[200][200] = {},OsId[200] = {};
    string stridss;
    int x = 0;
    int k = 0;
    ifstream reads;
    reads.open("C:/ProjectPizza/product.txt");
    while (!reads.eof())
    {
        string strid;

        reads >> pd.id;
        reads.ignore();
        getline(reads, pd.name);
        reads >> pd.thickS;
        reads >> pd.thickM;
        reads >> pd.thickL;
        reads >> pd.thinS;
        reads >> pd.thinM;
        reads >> pd.thinL;
        reads >> pd.priceS;
        reads >> pd.priceM;
        reads >> pd.priceL;

        strid = to_string(pd.id);

        Pid[x] = strid;
        Pname[x] = pd.name;
        PthickS[x] = pd.thickS;
        PthickM[x] = pd.thickM;
        PthickL[x] = pd.thickL;
        PthinS[x] = pd.thinS;
        PthinM[x] = pd.thinM;
        PthinL[x] = pd.thinL;
        PpriceS[x] = pd.priceS;
        PpriceM[x] = pd.priceM;
        PpriceL[x] = pd.priceL;
        x++;
    }
    reads.close();
    cout << "Enter Month : ";
    cin >> OM;
    cout << "Enter Year : ";
    cin >> OY;
    Orders O;
    ifstream read;
    read.open("C:/ProjectPizza/order.txt");
    while (!read.eof())
    {
        read >> O.OrderIds;
        read >> O.OrderQl;
        if(O.OrderQl == 1){
            Onum = 1;
        }else if(O.OrderQl == 2){
            Onum = 2;
        }else if(O.OrderQl == 3){
            Onum = 3;
        }
        for (int i = 0; i < Onum; i++)
        {
            read >> O.OrderPid;
            read >> O.Orderflour;
            read >> O.OrderSize;
            read >> O.OrderQ;

            OsPid[k][i] = O.OrderPid;
            Osflour[k][i] = O.Orderflour;
            Ossize[k][i] = O.OrderSize;
            OsQ[k][i] = O.OrderQ;
        }
        read >> O.OrderTT;
        read >> O.Orderwday;
        read >> O.Orderday;
        read >> O.Ordermount;
        read >> O.Orderyear;
        read >> O.Ordertime;
        int m = O.Ordermount - 1;
        int d = O.Orderwday;

        stridss = to_string(O.OrderIds);
        
        OsId[k] = stridss;
        OsQl[k] = O.OrderQl;
        Osday[k] = O.Orderday;
        Osmonth[k] = O.Ordermount;
        Osyear[k] = O.Orderyear;
        Oswday[k] = O.Orderwday;
        OsTT[k] = O.OrderTT;

        
        if(O.Ordermount == OM && O.Orderyear == OY){
            Sumttto = Sumttto + O.OrderTT;
            CWD = O.Orderwday;
            CD = O.Orderday;
            CM = O.Ordermount - 1;
            CY = O.Orderyear;
        }
        k++;
    }
    read.close();

    if(Sumttto == 0){
        cout << "Not! Data" << endl;
    }else{
        string strnames,strpid,strflour;
        int pris,prim,pril,PricePz = 0;

        for (int y = 0; y < 200; y++)
        {
            if(OsId[y] != "\0"){
                if(Osmonth[y] == OM && Osyear[y] == OY){
                cout << "=================================================================" << endl;
                cout << "Order ID " << OsId[y] << endl;
                cout << "=================================================================" << endl;
                cout << ":           Name            |  Flour  | Size | Quanlity | Price :" << endl;
                cout << "-----------------------------------------------------------------" << endl;
                    for (int j = 0; j <= OsQl[j]; j++)
                    {
                        for (int v = 0; v < 200; v++)
                        {
                        strpid = to_string(OsPid[y][j]);
                            if(strpid == Pid[v]){
                                strnames = Pname[v];

                                stringstream rps,rpm,rpl;
                                rps << PpriceS[v];
                                rps >> pris;
                                rpm << PpriceM[v];
                                rpm >> prim;
                                rpl << PpriceL[v];
                                rpl >> pril;
                                break;
                            }
                        }
                        if(OsPid[y][j] != 0){
                            if(Osflour[y][j] == 1){
                                strflour = "Thick";
                            }else{
                                strflour = "Thin";
                            }
                            if(Ossize[y][j] == "S"){
                                PricePz = pris;
                            }else if(Ossize[y][j] == "M"){
                                PricePz = prim;
                            }else if(Ossize[y][j] == "L"){
                                PricePz = pril;
                            }
                            cout << "  " << right << setw(23) << strnames << setw(4) << "|" << setw(7) 
                            << strflour << "  |" << setw(4) << Ossize[y][j] << "  |" << setw(5) << OsQ[y][j] << setw(6) 
                            << "  |" << setw(5) << OsQ[y][j] * PricePz << setw(2) << "  |" << endl;
                        }
                    }
                    cout << "-----------------------------------------------------------------" << endl;
                    cout << right << setw(32) << " Total " << OsTT[y] << " Baht "<< endl;
                    cout << "-----------------------------------------------------------------" << endl <<endl;
                }
            }
        }
        cout << month[CM] << " " << CY << endl;
        cout << "Total " << Sumttto << endl << endl;
    }
}

void ViewRePortYear(){
     int Onum,inum,Sumttto = 0,summ1 = 0;
    string cflour,dayss;
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    int OD,OM,OY,CWD,CD,CM,CY,checkvalue;
    string day[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    string month[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int Nmonth[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int Tmonth[12] = {};
    int x = 0;
    cout << "Enter Year : ";
    cin >> OY;
    Orders O;
    ifstream read;
    read.open("C:/ProjectPizza/order.txt");
    while (!read.eof())
    {
        read >> O.OrderIds;
        read >> O.OrderQl;
        if(O.OrderQl == 1){
            Onum = 1;
        }else if(O.OrderQl == 2){
            Onum = 2;
        }else if(O.OrderQl == 3){
            Onum = 3;
        }
        for (int i = 1; i <= Onum; i++)
        {
            read >> O.OrderPid;
            read >> O.Orderflour;
            read >> O.OrderSize;
            read >> O.OrderQ;
        }
        read >> O.OrderTT;
        read >> O.Orderwday;
        read >> O.Orderday;
        read >> O.Ordermount;
        read >> O.Orderyear;
        read >> O.Ordertime;
        int m = O.Ordermount - 1;
        int d = O.Orderwday,NNum;
        if(O.Orderyear == OY){
            Sumttto = Sumttto + O.OrderTT;
            CWD = O.Orderwday;
            CD = O.Orderday;
            CM = O.Ordermount - 1;
            CY = O.Orderyear;
            for (int n = 0; n < 12; n++)
            {
                if(O.Ordermount == Nmonth[n]){
                    Tmonth[n] = Tmonth[n] + O.OrderTT;
                }else{
                    Tmonth[n] = Tmonth[n];
                }
            }            
        }
    }
    read.close();

    if(Sumttto == 0){
        cout << "Not! Data" << endl;
    }else{
        for (int r = 0; r < 12; r++)
        {
            cout << month[r] << " Totol " << Tmonth[r] << endl;
        }
        cout << "Total " << Sumttto << endl;
    }
}

void Reportlist(){
    int select;
    bool check = false;
    do
    {
        cout << "1.ReportDay" << endl;
        cout << "2.ReportMonth" << endl;
        cout << "3.ReportYear" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter Select : ";
        cin >> select;
        if(select == 1){
            system("CLS");
            ViewRePortDay();
            check = false;
        }else if(select == 2){
            system("CLS");
            ViewRePortMonth();
            check = false;
        }else if(select == 3){
            system("CLS");
            ViewRePortYear();
            check = false;
        }else if(select == 4){
            check = true;
             system("CLS");
        }else{
            check = false;
            system("CLS");
        }
    } while (check == false);
    
}

void Complet(){
    Checkfile();
    bool check = false;
    do
    {
        // Productlist();
        cout << "1.Start Order" << endl;
        cout << "2.ADD" << endl;
        cout << "3.Read" << endl;
        cout << "4.Update" << endl;
        cout << "5.Delete" << endl;
        cout << "6.ViewOrder" << endl;
        cout << "7.SearchOrderReport" << endl;
        cout << "8.Exit" << endl;
        int option;
        cout << "Enter option : ";
        cin >> option;
        if (option == 1)
        {
            system("CLS");
            Pizza();
            // system("CLS");
        }else if (option == 2){
            Addproduct();
            system("CLS");
            check = false;
        }else if (option == 3){
            system("CLS");
            Readdata();
            check = false;
        }else if (option == 4){
            system("CLS");
            Updatedata();
            system("CLS");
            check = false;
        }else if (option == 5){
            system("CLS");
            deleteData();
            system("CLS");
            check = false;
        }else if (option == 6){
            system("CLS");
            vieworderlist();
            check = false;
        }else if (option == 7){
            system("CLS");
            Reportlist();
            check = false;
        }else if (option == 8){
            check = true;
        }else{
            system("CLS");
            check = false;
        }
    } while (check == false);
}

void Creatfile(){
    mkdir("C:/ProjectPizza");
    ofstream pidfile("C:/ProjectPizza/id.txt");
    pidfile << "6";
    pidfile.close();
    ofstream oidfile("C:/ProjectPizza/orderid.txt");
    oidfile << "0";
    oidfile.close();
    ofstream productfile("C:/ProjectPizza/product.txt");
    productfile << "\n" << "1";
    productfile << "\n" << "DoubleCheet";
    productfile << "\n" << "0";
    productfile << "\n" << "0";
    productfile << "\n" << "0";
    productfile << "\n" << "0";
    productfile << "\n" << "0";
    productfile << "\n" << "0";
    productfile << "\n" << "189";
    productfile << "\n" << "289";
    productfile << "\n" << "389";
    productfile << "\n" << "3";
    productfile << "\n" << "Double Pepperonis";
    productfile << "\n" << "0";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "179";
    productfile << "\n" << "279";
    productfile << "\n" << "379";
    productfile << "\n" << "4";
    productfile << "\n" << "Ham&Crab";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "10";
    productfile << "\n" << "189";
    productfile << "\n" << "289";
    productfile << "\n" << "389";
    productfile << "\n" << "5";
    productfile << "\n" << "Mighty Meat";
    productfile << "\n" << "12";
    productfile << "\n" << "12";
    productfile << "\n" << "12";
    productfile << "\n" << "12";
    productfile << "\n" << "12";
    productfile << "\n" << "12";
    productfile << "\n" << "189";
    productfile << "\n" << "289";
    productfile << "\n" << "389";
    productfile << "\n" << "6";
    productfile << "\n" << "Tom Yum Kung";
    productfile << "\n" << "21";
    productfile << "\n" << "21";
    productfile << "\n" << "21";
    productfile << "\n" << "21";
    productfile << "\n" << "21";
    productfile << "\n" << "21";
    productfile << "\n" << "267";
    productfile << "\n" << "367";
    productfile << "\n" << "467";
    productfile.close();
    ofstream orderfile("C:/ProjectPizza/order.txt");
    orderfile.close();
    ofstream openfile("C:/ProjectPizza/open.txt");
    openfile.close();
}

int main()
{
    // cout << "########   ####   #######   #######   ########" << endl;
    // cout << "##  ####   ####   ######    ######    ###  ###" << endl;
    // cout << "##  ####   ####      ##        ##     ###  ###" << endl;
    // cout << "########   ####     ##        ##      ########" << endl;
    // cout << "##         ####    ##        ##       ###  ###" << endl;
    // cout << "##         ####   ######    ######    ###  ###" << endl;
    // cout << "##         ####  #######   #######    ###  ###" << endl;

    ofstream myfile;
    myfile.open("C:/ProjectPizza/open.txt");
    if(myfile){
        Complet();
    }else{
        Creatfile();
        Complet();
    }
}