#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <direct.h>
#include <Windows.h>
#include <istream>
using namespace std;


HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int ID,Cnum = 0,OrderID,SSumtotal = 0;
bool cjp = false;
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

void readproduct(){
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    ifstream read;
    read.open("C:/ProjectPizza/product.txt");
    int x = 0;
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
        x++;
    }
    read.close();
}

void Addproduct()
{
    readproduct();
    bool adcheck = false,chchar = false,checkname = false;
    Product pd;
    cin.get();
    do
    {
        string strname,strnamesq,strnamd,tempstrname;
        string tempname[100] = {};
        string strchename,straddcheck[100] = {};
        cout << "Enter Pizza name : ";
        getline(cin, strname);
        char despace[50];
        char chanames[50];
        char strcheckn[50];
        char straddn[50];
        for (int i = 0; i < strname.size(); i++)
        {
            // cout << strname << " " << pd.name << endl;
            chanames[i] = strname[i];
            if(int((chanames[i]) >= 65 && int(chanames[i]) <= 90) || (chanames[i]) >= 97 && int(chanames[i]) <= 122){
                despace[i] = chanames[i];
                strnamesq += despace[i];
            }
        }
        for (int j = 0; j < 100; j++)
        {
            if(Pid[j] != "\0"){
                for (int l = 0; l < Pname[j].length(); l++)
                {
                    strchename = Pname[j];
                    strcheckn[l] = strchename[l];
                    if(strcheckn[l] != ' '){
                        straddn[l] = strcheckn[l];
                        strnamd += straddn[l];
                    }
                }
                straddcheck[j] = strnamd;
                strnamd = "";
            }
        }
        for (int x = 0; x < 100; x++)
        {
            if(straddcheck[x] != "\0"){
                transform(straddcheck[x].begin(),straddcheck[x].end(), straddcheck[x].begin(), ::tolower);
                transform(strnamesq.begin(),strnamesq.end(), strnamesq.begin(), ::tolower);
                if(straddcheck[x] == strnamesq){
                    strname = "";
                    strnamesq = "";
                    checkname = false;
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << straddcheck[x] << " Repeat" << endl;
                    SetConsoleTextAttribute(h,7);
                    break;
                }else{
                    checkname = true;
                }
            }
        }
    } while (checkname == false);
    
    do
    {
        cout << "Enter quantity Pizzathick S : ";
        cin >> pd.thickS;
        int tis,ns;
        ns = pd.thickS.size();
        char cis[10];
        stringstream ss;
        ss << pd.thickS;
        ss >> tis;
        for (int i = 0; i < ns; i++)
        {
            cis[i] = pd.thickS[i];
            if(int(cis[i]) < 48 || int(cis[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(tis >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter quantity Pizzathick M : ";
        cin >> pd.thickM;
        int tim,ns;
        ns = pd.thickM.size();
        char cim[10];
        stringstream ss;
        ss << pd.thickM;
        ss >> tim;
        for (int i = 0; i < ns; i++)
        {
            cim[i] = pd.thickM[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(tim >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter quantity Pizzathick L : ";
        cin >> pd.thickL;
        int til,ns;
        ns = pd.thickL.size();
        char cil[10];
        stringstream ss;
        ss << pd.thickL;
        ss >> til;
        for (int i = 0; i < ns; i++)
        {
            cil[i] = pd.thickL[i];
            if(int(cil[i]) < 48 || int(cil[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(til >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter quantity Pizzathin S : ";
        cin >> pd.thinS;
        int tnl,ns;
        ns = pd.thinS.size();
        char cns[10];
        stringstream ss;
        ss << pd.thinS;
        ss >> tnl;
       for (int i = 0; i < ns; i++)
        {
            cns[i] = pd.thickL[i];
            if(int(cns[i]) < 48 || int(cns[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(tnl >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter quantity Pizzathin M : ";
        cin >> pd.thinM;
        int tnm,ns;
        ns = pd.thinM.size();
        char cnm[10];
        stringstream ss;
        ss << pd.thinM;
        ss >> tnm;
        for (int i = 0; i < ns; i++)
        {
            cnm[i] = pd.thinM[i];
            if(int(cnm[i]) < 48 || int(cnm[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(tnm >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter quantity Pizzathin L : ";
        cin >> pd.thinL;
        int tnl,ns;
        ns = pd.thinL.size();
        char cnl[10];
        stringstream ss;
        ss << pd.thinL;
        ss >> tnl;
        for (int i = 0; i < ns; i++)
        {
            cnl[i] = pd.thinL[i];
            if(int(cnl[i]) < 48 || int(cnl[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(tnl >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter Price PizzaSize S : ";
        cin >> pd.priceS;
        int ps,ns;
        ns = pd.priceS.size();
        char cps[10];
        stringstream ss;
        ss << pd.priceS;
        ss >> ps;
        for (int i = 0; i < ns; i++)
        {
            cps[i] = pd.priceS[i];
            if(int(cps[i]) < 48 || int(cps[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(ps > 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter Price PizzaSize M : ";
        cin >> pd.priceM;
        int pm,ns;
        ns = pd.priceM.size();
        char cpm[10];
        stringstream ss;
        ss << pd.priceM;
        ss >> pm;
        for (int i = 0; i < ns; i++)
        {
            cpm[i] = pd.priceM[i];
            if(int(cpm[i]) < 48 || int(cpm[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(pm > 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
    adcheck = false;
    chchar = false;
    do
    {
        cout << "Enter Price PizzaSize L : ";
        cin >> pd.priceL;
        int pl,ns;
        ns = pd.priceL.size();
        char cpl[10];
        stringstream ss;
        ss << pd.priceL;
        ss >> pl;
        for (int i = 0; i < ns; i++)
        {
            cpl[i] = pd.priceL[i];
            if(int(cpl[i]) < 48 || int(cpl[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(pl > 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
    } while (adcheck == false);
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
    SetConsoleTextAttribute(h,14);
    // cout << "+=========================================================+" << endl;
    // cout << ": ID :         Name         : Price S : Price M : Price L :" << endl;
    // cout << "+---------------------------------------------------------+" << endl;
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
        SetConsoleTextAttribute(h,12);
        //  cout << right << ":" << setw(3) << Pid[x] << " : " << setw(20) << Pname[x] << " : " << setw(7) <<  PpriceS[x] << " :" << setw(8) << PpriceM[x] << " :" << setw(8) << PpriceL[x] << " :" << endl;
       cout << right << ":" << setw(3) << Pid[x] << " : " << setw(20) << Pname[x] << " : " << setw(7) << PthickS[x] << " : " << setw(6) <<  PthinS[x]
         << " : " << setw(7) << PthickM[x] << " : " << setw(6) << PthinM[x] << " : " << setw(7) <<  PthickL[x] << " : " << setw(6) << PthinL[x]
         << " : " << setw(7) <<  PpriceS[x] << " :" << setw(8) << PpriceM[x] << " :" << setw(8) << PpriceL[x] << " :" << endl;
        x++;
    }
    SetConsoleTextAttribute(h,10);
    // cout << "+=========================================================+" << endl;
    // cout << "+" << right << setw(38) << "Enter 0 to Retrun" << setw(20) << "+" << endl;
    // cout << "+=========================================================+" << endl;
    cout << "+==================================================================================================================+" << endl;
    cout << "+" << right << setw(65) << "Enter 0 to Retrun" << setw(50) << "+" << endl;
    cout << "+==================================================================================================================+" << endl;
    read.close();
    SetConsoleTextAttribute(h,7);
}

void Productlistflour(int Proid)
{
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    ifstream read;
    read.open("C:/ProjectPizza/product.txt");
    int x = 0;
    SetConsoleTextAttribute(h,14);
    cout << "+====================================================+" << endl;
    cout << ": ID :         Name         : Thickflour : Thinflour :" << endl;
    cout << "+----------------------------------------------------+" << endl;
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
        if(pd.id == Proid){
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
        SetConsoleTextAttribute(h,12);
        cout << right << ":" << setw(3) << pd.id << " : " << setw(20) << pd.name << " : " << setw(10) 
        << SiTkS+SiTkM+SiTkL  << " :" << setw(10) << SiTnS+SiTnM+SiTnL << " :" << endl;
        }
    }
    SetConsoleTextAttribute(h,10);
    cout << "+====================================================+" << endl;
    read.close();
    SetConsoleTextAttribute(h,7);
}

void ProductlistSize(int Proids, int flours)
{
    Product pd;
    int SiTkS, SiTkM, SiTkL, SiTnS, SiTnM, SiTnL;
    ifstream read;
    read.open("C:/ProjectPizza/product.txt");
    int x = 0;
    SetConsoleTextAttribute(h,14);
    if(flours == 1){
        cout << "+======================================================+" << endl;
        cout << ": ID :         Name         : ThickS : ThickM : ThickL :" << endl;
        cout << "+------------------------------------------------------+" << endl;
    }else{
        cout << "+===================================================+" << endl;
        cout << ": ID :         Name         : ThinS : ThinM : ThinL :" << endl;
        cout << "+---------------------------------------------------+" << endl;
    }
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
        if(pd.id == Proids){
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
        if(flours == 1){
        SetConsoleTextAttribute(h,12);
        cout << right << ":" << setw(3) << pd.id << " : " << setw(20) << pd.name << " : " << setw(6) 
        << pd.thickS << " :" << setw(7) << pd.thickM << " :" << setw(7) << pd.thickL << " :" << endl;
        }else{
        SetConsoleTextAttribute(h,12);
        cout << right << ":" << setw(3) << pd.id << " : " << setw(20) << pd.name << " : " << setw(5) 
        << pd.thinS << " :" << setw(6) << pd.thinM << " :" << setw(6) << pd.thinL << " :" << endl;
        }
        }
    }
    if(flours == 1){
    SetConsoleTextAttribute(h,10);
    cout << "+======================================================+" << endl;
    read.close();
    SetConsoleTextAttribute(h,7);
    }else{
    SetConsoleTextAttribute(h,10);
    cout << "+===================================================+" << endl;
    read.close();
    SetConsoleTextAttribute(h,7);
    }
}

int searchData()
{
    int id;
    bool checkid = false,chchar = false;
    string strid;
    char cim[50];
    do
    {
        cout << "Enter Pizza id want to search : ";
        cin >> strid;
        for (int i = 0; i < strid.length(); i++)
        {
            cim[i] = strid[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
        stringstream dd;
        dd << strid;
        dd >> id;
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
        }
    } while (checkid == false);
}

void Updatedata()
{
    readproduct();
    bool checkid = false,checkname = false;
    int Pids, id,checkids = 0;
    bool adcheck = false,chchar = false;
    id = searchData();
    cout << "You want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
    Product newData;
    cin.get();
    do
    {
        string strname,strnamesq = "",strnamd,tempstrname,strid;
        string tempname[100] = {};
        string strchename,straddcheck[100] = {};
        int ids;
        cout << "Enter Pizza name : ";
        getline(cin, newData.name);
        strname = newData.name;
        char despace[50];
        char chanames[50];
        char strcheckn[50];
        char straddn[50];
        for (int i = 0; i < strname.size(); i++)
        {
            chanames[i] = strname[i];
            if(int((chanames[i]) >= 65 && int(chanames[i]) <= 90) || (chanames[i]) >= 97 && int(chanames[i]) <= 122){
                despace[i] = chanames[i];
                strnamesq += despace[i];
            }
        }
        for (int j = 0; j < 100; j++)
        {
            if(Pid[j] != "\0"){
                strid = to_string(id);
                if(Pid[j] == strid){
                    ids = j;
                }
                for (int l = 0; l < Pname[j].length(); l++)
                {
                    strchename = Pname[j];
                    strcheckn[l] = strchename[l];
                    if(strcheckn[l] != ' '){
                        straddn[l] = strcheckn[l];
                        strnamd += straddn[l];
                    }
                }
                straddcheck[j] = strnamd;
                strnamd = "";
            }
        }
        for (int x = 0; x < 100; x++)
        {
            transform(straddcheck[id].begin(),straddcheck[id].end(), straddcheck[id].begin(), ::tolower);
            transform(straddcheck[x].begin(),straddcheck[x].end(), straddcheck[x].begin(), ::tolower);
            transform(strnamesq.begin(),strnamesq.end(), strnamesq.begin(), ::tolower);
            if(straddcheck[x] != "\0"){
                    if(straddcheck[x] == strnamesq && strnamesq != straddcheck[ids]){
                        strnamesq = "";
                        checkname = false;
                        system("CLS");
                        SetConsoleTextAttribute(h,4);
                        cout << straddcheck[x] << " Repeat" << endl;
                        SetConsoleTextAttribute(h,7);
                        break;
                    }else{
                        checkname = true;
                    }
            }
        }
    } while (checkname == false);
        do
        {
        cout << "Enter quantity Pizzathick S : ";
        cin >> newData.thickS;
        int tis,ns;
        ns = newData.thickS.size();
        char cis[10];
        stringstream ss;
        ss << newData.thickS;
        ss >> tis;
        for (int i = 0; i < ns; i++)
        {
            cis[i] = newData.thickS[i];
            if(int(cis[i]) < 48 || int(cis[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(tis >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter quantity Pizzathick M : ";
        cin >> newData.thickM;
        int tim,ns;
        ns = newData.thickM.size();
        char cim[10];
        stringstream ss;
        ss << newData.thickM;
        ss >> tim;
        for (int i = 0; i < ns; i++)
        {
            cim[i] = newData.thickM[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(tim >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter quantity Pizzathick L : ";
        cin >> newData.thickL;
        int til,ns;
        ns = newData.thickL.size();
        char cil[10];
        stringstream ss;
        ss << newData.thickL;
        ss >> til;
        for (int i = 0; i < ns; i++)
        {
            cil[i] = newData.thickL[i];
            if(int(cil[i]) < 48 || int(cil[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(til >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
    {
        cout << "Enter quantity Pizzathin S : ";
        cin >> newData.thinS;
        int tnl,ns;
        ns = newData.thinS.size();
        char cns[10];
        stringstream ss;
        ss << newData.thinS;
        ss >> tnl;
        for (int i = 0; i < ns; i++)
        {
            cns[i] = newData.thickL[i];
            if(int(cns[i]) < 48 || int(cns[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(tnl >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter quantity Pizzathin M : ";
        cin >> newData.thinM;
        int tnm,ns;
        ns = newData.thinM.size();
        char cnm[10];
        stringstream ss;
        ss << newData.thinM;
        ss >> tnm;
        for (int i = 0; i < ns; i++)
        {
            cnm[i] = newData.thinM[i];
            if(int(cnm[i]) < 48 || int(cnm[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(tnm >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter quantity Pizzathin L : ";
        cin >> newData.thinL;
        int tnl,ns;
        ns = newData.thinL.size();
        char cnl[10];
        stringstream ss;
        ss << newData.thinL;
        ss >> tnl;
        for (int i = 0; i < ns; i++)
        {
            cnl[i] = newData.thinL[i];
            if(int(cnl[i]) < 48 || int(cnl[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(tnl >= 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter Price PizzaSize S : ";
        cin >> newData.priceS;
        int ps,ns;
        ns = newData.priceS.size();
        char cps[10];
        stringstream ss;
        ss << newData.priceS;
        ss >> ps;
        for (int i = 0; i < ns; i++)
        {
            cps[i] = newData.priceS[i];
            if(int(cps[i]) < 48 || int(cps[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
       if(chchar == true){
            if(ps > 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter Price PizzaSize M : ";
        cin >> newData.priceM;
        int pm,ns;
        ns = newData.priceM.size();
        char cpm[10];
        stringstream ss;
        ss << newData.priceM;
        ss >> pm;
        for (int i = 0; i < ns; i++)
        {
            cpm[i] = newData.priceM[i];
            if(int(cpm[i]) < 48 || int(cpm[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(pm > 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
        do
        {
        cout << "Enter Price PizzaSize L : ";
        cin >> newData.priceL;
        int pl,ns;
        ns = newData.priceL.size();
        char cpl[10];
        stringstream ss;
        ss << newData.priceL;
        ss >> pl;
        for (int i = 0; i < ns; i++)
        {
            cpl[i] = newData.priceL[i];
            if(int(cpl[i]) < 48 || int(cpl[i]) > 57){
                chchar = false;
                break;
            }else{
                chchar = true;
            }
        }
        if(chchar == true){
            if(pl > 0){
            adcheck = true;
            }else{
            adcheck = false;
            }
        }
        } while (adcheck == false);
        adcheck = false;
        chchar = false;
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

void Cancelorder();

void SelectPizza(){
    Productlist();
    int slp, intid , no,intkS,intkM,intkL,intnS,intnM,intnL,intsum,intPS,intPM,intPL,Noa;
    int tkiS, tkiM, tkiL, tniS, tniM, tniL, Qt = 0,chks,quan,conselect,flour;
    string Sizes,strslp;
    char  slpaz[50];
    bool ckp = false, cks = false,ckt = false,ckc = false,checkcha = false;
        do{
            cout << "Enter Select PizzaID : ";
            cin >> strslp;
            for (int o = 0; o < strslp.size(); o++)
            {
               slpaz[o] = strslp[o];
               if(int(slpaz[o]) < 48 || int(slpaz[o]) > 57){
                checkcha = false;
                break;
               }else{
                checkcha = true;
               }
            }
            if(checkcha == true){
            checkcha = false;
            stringstream kk;
            kk << strslp;
            kk >> slp;
            for (int i = 0; i < 100; i++){
                stringstream sw;
                sw << Pid[i];
                sw >> intid;
                if (slp == intid){
                    ckp = true;
                    no = i;
                    chks = 1;
                    break;
                }else if(slp == 0){
                    Cancelorder();
                    cjp = true;
                    ckp = true;
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
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] <<  "Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    ckp = false;
                    chks = 0;
                }
            }
            }
            } while (ckp == false);
            system("CLS");
            if(cjp == false){
            int chh = 0;
            do{
            // if(chh == 1){
            //     Productlist();
            // }
            Productlistflour(slp);
            string strfo;
            char chfo[10];
            bool checkfol = false;
            cout << "1.flour thick" << endl;
            cout << "2.flour thin" << endl;
            cout << "Enter flour : ";
            cin >> strfo;
            for (int n = 0; n < strfo.size(); n++)
            {
                chfo[n] = strfo[n];
                if(int(chfo[n]) < 48 || int(chfo[n]) > 57){
                    checkfol = false;
                    chh = 0;
                    system("CLS");
                    break;
                }else if(int(chfo[n]) < 49 || int(chfo[n]) > 50){
                    checkfol = false;
                    chh = 0;
                    system("CLS");
                    break;
                }else{
                    checkfol = true;
                }
            }
            if(checkfol == true){
            checkfol = false;
            stringstream ff;
            ff << strfo;
            ff >> flour;
            ProductlistSize(slp,flour);
            cout << "Enter (S/M/L) Size Pizza : ";
            cin >> Sizes;
            transform(Sizes.begin(), Sizes.end(), Sizes.begin(), ::toupper);
            if(Sizes == "S" && flour == 1){
                if(PthickS[no] == "0"){
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] << " flour thick S Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "M" && flour == 1){
                if(PthickM[no] == "0"){
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] << " flour thick M Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "L" && flour == 1){
                if(PthickL[no] == "0"){
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] << " flour thick L Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "S" && flour == 2){
                if(PthinS[no] == "0"){
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] << " flour thin S Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "M" && flour == 2){
                if(PthinM[no] == "0"){
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] << " flour thin M Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    cks = false;
                }else{
                    cks = true;
                }
            }else if(Sizes == "L" && flour == 2){
                if(PthinL[no] == "0"){
                    system("CLS");
                    SetConsoleTextAttribute(h,4);
                    cout << Pname[no] << " flour thin L Out of Stock" << endl;
                    SetConsoleTextAttribute(h,7);
                    cks = false;
                }else{
                    cks = true;
                }
            }else{
                chh = 1;
                cks = false;
                system("CLS");
            }
            }
        } while (cks == false);

        do
        {
            string strqua;
            char chquan[10];
            bool checkquan = false;
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
            cin >> strqua;
            for (int k = 0; k < strqua.size(); k++)
            {
                chquan[k] = strqua[k];
                if(int(chquan[k]) < 48 || int(chquan[k]) > 57){
                    checkquan = false;
                    break;
                }else{
                    checkquan = true;
                }
            }
            if(checkquan == true){
            checkquan = false;
            stringstream qq;
            qq << strqua;
            qq >> quan;
            if(Sizes == "S" && flour == 1){
                if(quan > 0 && quan <= intkS){
                    ckt = true;
                }else{
                    SetConsoleTextAttribute(h,6);
                    cout << Pname[no] << " Size S flour thick Limited to " << intkS << endl;
                    SetConsoleTextAttribute(h,7);
                    ckt = false;
                }
            }else if(Sizes == "M" && flour == 1){
                if(quan > 0 && quan <= intkM){
                    ckt = true;
                }else{
                    SetConsoleTextAttribute(h,6);
                    cout << Pname[no] << " Size M flour thick Limited to " << intkM << endl;
                    SetConsoleTextAttribute(h,7);
                    ckt = false;
                }
            }else if(Sizes == "L" && flour == 1){
                if(quan > 0 && quan <= intkL){
                    ckt = true;
                }else{
                     SetConsoleTextAttribute(h,6);
                    cout << Pname[no] << " Size L flour thick Limited to " << intkL << endl;
                    SetConsoleTextAttribute(h,7);
                    ckt = false;
                }
            }else if(Sizes == "S" && flour == 2){
                if(quan > 0 && quan <= intnS){
                    ckt = true;
                }else{
                    SetConsoleTextAttribute(h,6);
                    cout << Pname[no] << " Size S flour thin Limited to " << intnS << endl;
                    SetConsoleTextAttribute(h,7);
                    ckt = false;
                }
            }
            else if(Sizes == "M" && flour == 2){
                if(quan > 0 && quan <= intnM){
                    ckt = true;
                }else{
                    SetConsoleTextAttribute(h,6);
                    cout << Pname[no] << " Size M flour thin Limited to " << intnM << endl;
                    SetConsoleTextAttribute(h,7);
                    ckt = false;
                }
            }
            else if(Sizes == "L" && flour == 2){
                if(quan > 0 && quan <= intnL){
                    ckt = true;
                }else{
                    SetConsoleTextAttribute(h,6);
                    cout << Pname[no] << " Size L flour thin Limited to " << intnL << endl;
                    SetConsoleTextAttribute(h,7);
                    ckt = false;
                }
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
    bool checkmoney = false,checkm = false;
    do{
        char chmoney[20];
        string strmoney;
        cout << ": ============================================== :" << endl;
        cout << right << ": amount to be paid : " << setw(21) << Totalsumss << " Baht" << endl;
        cout << ": Enter Money : "<< setw(22) << " ";
        cin >> strmoney;
        for (int v = 0; v < strmoney.size(); v++)
        {
            chmoney[v] = strmoney[v];
            if(int(chmoney[v]) < 48 || int(chmoney[v]) > 57){
                checkm = false;
                break;
            }else{
                checkm = true;
            }
        }
        if(checkm == true){
            stringstream ww;
            ww << strmoney;
            ww >> money;
            if(money < Totalsumss){
                checkmoney = false;
            }else{
                checkmoney = true;
            }
        }
    } while (checkmoney == false);
        balanc = money - Totalsumss;
        SetConsoleTextAttribute(h,11);
        cout << right << ": give the change :" << setw(25)  << balanc << " Baht" << endl ;
         SetConsoleTextAttribute(h,7);
        cout << ": ---------------------------------------------- :" << endl;
        cout << ":";
        SetConsoleTextAttribute(h,2);
        cout << right << setw(31) << "Order Success" << setw(18);
        SetConsoleTextAttribute(h,7);
        cout << ":" << endl;
        cout << ": ============================================== :" << endl;
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
        if(cjp == true){
            ckc = true;
            cjp = false;
        }else{
        if(Cnum == 2){
            cout << "1.ViewOrder" << endl;
            cout << "2.CancelOrder" << endl;
            cout << "3.ConfirmOrder" << endl;
            cout << "Enter Select : ";
            cin >> conselect;
            if(conselect == 1){
        vieworder();
            }else if(conselect == 2){
               cout << "Enter (";
                SetConsoleTextAttribute(h,2);
                cout << "y";
                SetConsoleTextAttribute(h,7);
                cout << "/";
                SetConsoleTextAttribute(h,4);
                cout << "n";
                SetConsoleTextAttribute(h,7);
                cout << ") ";
                cin >> can;
                if(can == 'y'){
                    system("CLS");
                    Cancelorder();
                    ckc = true;
                }else{
                    ckc = false;
                }
            }else if(conselect == 3){
               cout << "Enter (";
                SetConsoleTextAttribute(h,2);
                cout << "y";
                SetConsoleTextAttribute(h,7);
                cout << "/";
                SetConsoleTextAttribute(h,4);
                cout << "n";
                SetConsoleTextAttribute(h,7);
                cout << ") ";
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
                cout << "Enter (";
                SetConsoleTextAttribute(h,2);
                cout << "y";
                SetConsoleTextAttribute(h,7);
                cout << "/";
                SetConsoleTextAttribute(h,4);
                cout << "n";
                SetConsoleTextAttribute(h,7);
                cout << ") ";
                cin >> can;
                if(can == 'y'){
                    system("CLS");
                    Cancelorder();
                    ckc = true;
                }else{
                    ckc = false;
                }
            }else if(conselect == 4){
                cout << "Enter (";
                SetConsoleTextAttribute(h,2);
                cout << "y";
                SetConsoleTextAttribute(h,7);
                cout << "/";
                SetConsoleTextAttribute(h,4);
                cout << "n";
                SetConsoleTextAttribute(h,7);
                cout << ") ";
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
    bool chcharOD = false;
    do
    {
        string strOD;
        cout << "Enter Day : ";
        cin >> strOD;
        char cim[10];
        stringstream ss;
        ss << strOD;
        ss >> OD;
        for (int i = 0; i < strOD.length(); i++)
        {
            cim[i] = strOD[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chcharOD = false;
                break;
            }else{
                chcharOD = true;
            }
        }
    } while (chcharOD == false);
    bool chcharOM = false;
    do
    {
        string strOM;
        cout << "Enter Month : ";
        cin >> strOM;
        char cim[10];
        stringstream ss;
        ss << strOM;
        ss >> OM;
        for (int i = 0; i < strOM.length(); i++)
        {
            cim[i] = strOM[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chcharOM = false;
                break;
            }else{
                chcharOM = true;
            }
        }
    } while (chcharOM == false);
    bool chcharOY = false;
    do
    {
        string strOY;
        cout << "Enter Year : ";
        cin >> strOY;
        char cim[10];
        stringstream ss;
        ss << strOY;
        ss >> OY;
        for (int i = 0; i < strOY.length(); i++)
        {
            cim[i] = strOY[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chcharOY = false;
                break;
            }else{
                chcharOY = true;
            }
        }
    } while (chcharOY == false);
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
        SetConsoleTextAttribute(h,4);
        cout << "Not! Data" << endl;
        SetConsoleTextAttribute(h,7);
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

void ViewRePortToDay(){
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
    time_t nows;

    struct tm datelc;

    nows = time(NULL);

    datelc = *localtime(&nows);
    OD = datelc.tm_mday;
    OM = datelc.tm_mon + 1;
    OY = datelc.tm_year + 1900;
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
        SetConsoleTextAttribute(h,4);
        cout << "Not! Data" << endl;
        SetConsoleTextAttribute(h,7);
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
    bool chcharOM = false;
    do
    {
        string strOM;
        cout << "Enter Month : ";
        cin >> strOM;
        char cim[10];
        stringstream ss;
        ss << strOM;
        ss >> OM;
        for (int i = 0; i < strOM.length(); i++)
        {
            cim[i] = strOM[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chcharOM = false;
                break;
            }else{
                chcharOM = true;
            }
        }
    } while (chcharOM == false);
    bool chcharOY = false;
    do
    {
        string strOY;
        cout << "Enter Year : ";
        cin >> strOY;
        char cim[10];
        stringstream ss;
        ss << strOY;
        ss >> OY;
        for (int i = 0; i < strOY.length(); i++)
        {
            cim[i] = strOY[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chcharOY = false;
                break;
            }else{
                chcharOY = true;
            }
        }
    } while (chcharOY == false);
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
         SetConsoleTextAttribute(h,4);
        cout << "Not! Data" << endl;
         SetConsoleTextAttribute(h,7);
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
    bool chcharOY = false;
    do
    {
        string strOY;
        cout << "Enter Year : ";
        cin >> strOY;
        char cim[10];
        stringstream ss;
        ss << strOY;
        ss >> OY;
        for (int i = 0; i < strOY.length(); i++)
        {
            cim[i] = strOY[i];
            if(int(cim[i]) < 48 || int(cim[i]) > 57){
                chcharOY = false;
                break;
            }else{
                chcharOY = true;
            }
        }
    } while (chcharOY == false);
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
        SetConsoleTextAttribute(h,4);
        cout << "Not! Data" << endl;
        SetConsoleTextAttribute(h,7);
    }else{
        cout << "+======================================+" << endl;
        cout << ":       Month       :       Totol      :" << endl;
        cout << "+======================================+" << endl;
        for (int r = 0; r < 12; r++){
            cout << right << ":" << setw(19) << month[r] << ":" << setw(18) << Tmonth[r] << ":" << endl;
        }
        cout << "+======================================+" << endl;
        SetConsoleTextAttribute(h,11);
        cout << right << setw(28) << "Total " << Sumttto << " Bath" << " :" << endl;
        SetConsoleTextAttribute(h,7);
        cout << "+======================================+" << endl;
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
    bool check = false,checkcha = false;
    do
    {
        // Productlist();
        // SetConsoleTextAttribute(h,4);
        // cout << "1.Start Order" << endl;
        // SetConsoleTextAttribute(h,7);
        // cout << "2.ADD" << endl;
        // cout << "3.Read" << endl;
        // cout << "4.Update" << endl;
        // cout << "5.Delete" << endl;
        // cout << "6.ViewOrder" << endl;
        // cout << "7.ViewOrderToday" << endl;
        // cout << "8.SearchOrderReport" << endl;
        // cout << "9.Exit" << endl;
        cout << "1.Start Order" << endl;
        cout << "2.ADD" << endl;
        cout << "3.Read" << endl;
        cout << "4.Update" << endl;
        cout << "5.ViewOrder" << endl;
        cout << "6.ViewOrderToday" << endl;
        cout << "7.SearchOrderReport" << endl;
        cout << "8.Exit" << endl;
        int option;
        char choption[10];
        string stroption;
        cout << "Enter option : ";
        cin >> stroption;
        for (int v = 0; v < stroption.size(); v++)
        {
            choption[v] = stroption[v];
            if(int(choption[v]) < 48 || int(choption[v]) > 57){
                checkcha = false;
                break;
            }else{
                checkcha = true;
            }
        }
        if(checkcha == true){
        stringstream ii;
        ii << stroption;
        ii >> option;
        if (option == 1)
        {
            system("CLS");
            Pizza();
            system("CLS");
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
        // }else if (option == 5){
        //     system("CLS");
        //     deleteData();
        //     system("CLS");
        //     check = false;
        }else if (option == 5){
            system("CLS");
            vieworderlist();
            check = false;
        }else if (option == 6){
            system("CLS");
            ViewRePortToDay();
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
        }else{
            system("CLS");
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