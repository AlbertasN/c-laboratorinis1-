#include <bits/stdc++.h> // geriausia biblioteka apjungianti daug kitu
using namespace std;

string ns; //sukuriame viena globalu kad lengviau veliau butu panaudoti

class knyga // aprasome kas bus klaseje
{
  private: // aprasome privacius kintamuosius
  string autorius;
  string pavadinimas;
  int metai;
  string leidykla;
  double kaina;
  double tirazas;

  public: // sukuriame settus 
  void setAutorius(string a){autorius=a;}
  void setPavadinimas(string p){pavadinimas=p;}
  void setMetai(int m){metai=m;}
  void setLeidykla(string l){leidykla=l;}
  void setKaina(double k){kaina=k;}
  void setTirazas(double t){tirazas=t;}

  string getAutorius(){return autorius;} //kuriame getterius 
  string getPavadinimas(){return pavadinimas;}
  int getMetai(){return metai;}
  string getLeidykla(){return leidykla;}
  double getKaina(){return kaina;}
  double getTirazas(){return tirazas;}
};

void removeSpaces(string str) // komanda skirta panaikinti spacesus kurie yra virs 2, pamirsau kaip su setw tai sita padariau
{  
    for (int j = 0; str.length()-1; j++) 
    {
        if(str[j]==' ')
        {
          if(str[j+1]==' ')
          {
            ns=str.erase(j, str.size());
            break;
          }
        }     
    }        
}

int main(void) {

  knyga K[100]; //klases irasymas
  int n=5;
  char zodis1[20]=""; //zodziai skirti istraukti duomenis is failo
  char zodis2[14]="";
  char zodis3[19]="";
  double skaicius;
  string V[n]; // gettinti masyvai duomenu
  string P[n];
  string L[n];
  int M[n];
  double Kaina[n];
  double Tirazas[n];
  double tempas;
  string Le[5];
  int a=1;
  int pradinist=0;

  ifstream fd; // atidarome faila
  fd.open("duom.txt");
  for(int i=0; i<n; i++)
  {
    fd.read(zodis1, sizeof(zodis1)); // istraukiame pirmuosius stringus
    removeSpaces(zodis1);
    K[i].setAutorius(ns);
    V[i]=K[i].getAutorius();
    fd.read(zodis2, sizeof(zodis2));// istraukiame antruosius stringus
    removeSpaces(zodis2);
    K[i].setPavadinimas(ns);
    P[i]=K[i].getPavadinimas();
    fd.read(zodis3, sizeof(zodis3));// istraukiame treciuosius stringus
    removeSpaces(zodis3);
    K[i].setLeidykla(ns);
    L[i]=K[i].getLeidykla();
    fd>>skaicius;
    K[i].setMetai(skaicius);
    M[i]=K[i].getMetai(); // traukiame duomenis is failo(double)
    fd>>skaicius;
    K[i].setKaina(skaicius);
    Kaina[i]=K[i].getKaina();
    fd>>skaicius;
    K[i].setTirazas(skaicius);
    Tirazas[i]=K[i].getTirazas();
    fd.ignore(1, '\n');
    
  }
  fd.close(); // uzdarome faila
  
  int sk; //aprasome kintamuosius kurie pades rasant koda
  char pasirinktasA[20]="";
  char pasirinktasP[20]="";
  char pasirinktasL[20]="";
  char temp[20];
  double sumaK=0;
  double sumaT=0;
  double bendrasSK=0;
  double skaicius1=0, skaicius2=0;
  int Pan1[5], Pan2[5], Pan3[5], Pan4[5]; //5case 4kriterijai
  int p=0;
  //rasome nepatogu user interface

  cout<<"Jeigu norite pamatyti visa sarasa spauskite *1*"<<endl;
  cout<<"Jeigu norite pamatyti autoriau vidutine knygos kaina ir tiraza spauskite *2*"<<endl;
  cout<<"Paieska pagal knygos autoriu ir leidykla spauskite *3*"<<endl;
  cout<<"Paieska pagal knygos autoriu, leidykla, kaina ir tiraza spauskite *4*"<<endl;
  cout<<"Pasirinktos leidyklos knygu rusiavimas pagal autoriu ir tiraza *5*"<<endl;
  cin>>sk;
  //duodame naudotujui pasirinkimus
  switch(sk){
    case 1:
    for(int i=0; i<n; i++)//sitas pasirinkimas parodo visa lentele
    {
      cout<<V[i]<<" "<<P[i]<<" "<<L[i]<<" "<<M[i]<<" "<<Kaina[i]<<" "<<Tirazas[i]<<endl;
    }
    break;
    case 2: //sitas parodo vidutine kaina ir tiraza
    cin.ignore();//ivedamas antras cin.get(), nes \n islieka buffery
    cout<<"Prasau iveskite pasirinkta autoriu: "<<endl;
  cin.get(pasirinktasA, 80, '\n');
  cin.get();
  for(int i=0; i<n; i++)
  {
    if(pasirinktasA==V[i]) //tikriname ar pasirinktas autorius yra duom.txt
    {
      sumaK+=Kaina[i];
      sumaT+=Tirazas[i];
      bendrasSK++;
    }
  }
  cout<<pasirinktasA<<" knygu vidutine kaina: "<<sumaK/bendrasSK<<" , o tirazu skaicius: "<<sumaT/bendrasSK<<endl;
    break;
    case 3: //sitas pagal autoriu ir knyga parodo info
    cout<<"Prasau iveskite pasirinkta autoriu: "<<endl;
    cin.ignore();//ivedamas antras cin.get(), nes \n islieka buffery
  cin.get(pasirinktasA, 20, '\n');
  cin.get();  //ivedamas antras cin.get(), nes \n islieka buffery
  cout<<"Prasau iveskite pasirinkta knyga: "<<endl;
  cin.get(pasirinktasP, 20, '\n');
  
  for(int i=0; i<n; i++)
  {
    if(pasirinktasA==V[i]) //tikriname ar pasirinktas autorius yra duom.txt
    {
      for(int j=0; j<n; j++)
      {
        if(pasirinktasP==P[j]) //tikriname ar pasirinktas pavadinimas yra duom.txt
        {
          p=j;
        }
      }
    }
  }
  cout<<"************************"<<endl;//parodome kokia informacija turime
  cout<<"Autorius: "<<V[p]<<endl;
  cout<<"Knyga: "<<P[p]<<endl;
  cout<<"Leidykla: "<<L[p]<<endl;
  cout<<"Metai: "<<M[p]<<endl;
  cout<<"Kaina: "<<Kaina[p]<<endl;
  cout<<"Tirazas: "<<Tirazas[p]<<endl;
    break;
    case 4: //sitas irasant autoriu, leidykla, kaina ir tiraza parodo info
    
  cin.ignore();
  cout<<"Prasau iveskite pasirinkta autoriu: "<<endl;
  cin.get(pasirinktasA, 20, '\n');
  cin.get(); //ivedamas antras cin.get(), nes \n islieka buffery
  cout<<"Prasau iveskite pasirinkta leidykla: "<<endl;
  cin.get(pasirinktasL, 20, '\n');
  cin.get();  //ivedamas antras cin.get(), nes \n islieka buffery
  cout<<"Prasau iveskite knygos kaina: "<<endl;
  cin>>skaicius1;
  cout<<"Prasau iveskite knygos tirazas: "<<endl;
  cin>>skaicius2;
  for(int i=0; i<n; i++) //tikriname kiek sutampa kiekvienos duotos kategorijos duomenu
  {
    if(pasirinktasA==V[i])// visi P[]yra nunulinti todel prie ju pridedant gausime reikiamus skaicius veliau ieskant pagal kriterijus informacijos 
    {
      Pan1[i]++;
    }
    if(pasirinktasL==L[i])
    {
      Pan2[i]++;
      
    }
    if(skaicius1==Kaina[i])
    {
      Pan3[i]++;
    }
    if(skaicius2==Tirazas[i])
    {
      Pan4[i]++;
    }
  }
  for(int i=0; i<n; i++) //jeigu sutampa visi reikalngi gauname reikiama skaiciu, kuris leis suzinoti elemento numeri masyvuose kur yra duomenys
  {
    if(Pan1[i]+Pan2[i]+Pan3[i]+Pan4[i]==4)
    {
      p=i;
    }
  }

  
  if(p<5)//jeigu p gaunasi neegzistuojantis parodome kad jo nera 
  {
     cout<<"************************"<<endl;
     cout<<"Autorius: "<<V[p]<<endl;
     cout<<"Knyga: "<<P[p]<<endl;
     cout<<"Leidykla: "<<L[p]<<endl;
     cout<<"Metai: "<<M[p]<<endl;
     cout<<"Kaina: "<<Kaina[p]<<endl;
     cout<<"Tirazas: "<<Tirazas[p]<<endl;
  }
  else
  cout<<"Nerastas autorius ir jo duomenys"<<endl;
    break;
    case 5: //sitas isrikiuoja pagal tiraza pasirinkta leidykla ir autoriu
    cin.ignore();//ivedamas antras cin.get(), nes \n islieka buffery
    cout<<"Pasirinkite leidykla: "<<endl;
  cin.get(pasirinktasL, 20, '\n');
  for(int i=0; i<n; i++)
  {
    if(pasirinktasL==L[i]) //tikriname ar pasirinkta leidykla yra duom.txt ir skaiciuojame kiek ju yra
    {

      a=i; //galutinis taskas elementu
      pradinist++; //pradinis taskas nuo elementu pradzios
    }
  }
  a+=1;
  pradinist=a-pradinist;
  for(int i=pradinist; i<a-1; i++)
  {
    for(int j=i+1; j<a; j++)
    {
      if(Tirazas[i]<Tirazas[j]) //lyginame tirazus
      {
        int temp = Tirazas[i];  //apkeiciame tirazus
        Tirazas[i] = Tirazas[j];  
        Tirazas[j] = temp;

        swap(Kaina[i], Kaina[j]); //keiciame visus duomenis pagal tirazu eiliskuma
        swap(M[i], M[j]);
        swap(P[i], P[j]);
      }
    }
  }
  for(int i=pradinist; i<a; i++) //isvedame ussortinta informacija
  {
    cout<<V[i]<<" "<<P[i]<<" "<<L[i]<<" "<<M[i]<<" "<<Kaina[i]<<" "<<Tirazas[i]<<endl;
  }
    break;
  }
  return 0;
}