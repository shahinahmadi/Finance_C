#include<iostream>
#include <cstdio>
#include "TGraph.h"
#include<vector>
#include <fstream>
#include <string>
#include "TFile.h"

using namespace std;


void Finance(string filename){
  vector<double>days, Famel1, Famel2, Dey1, Faspa1, Samera1, Shabandar1, Hakeshti1;
  
  TFile f("Graph.root","recreate");
  f.mkdir("a");
  f.cd("a");
 
  ifstream myfile(filename);
  if (myfile.is_open()){
    string Fameli1, Fameli2, Dey, Faspa, Samera, Shabandar, Hakeshti;
    double F1, F2, De, Fas, Sa, Shab, Hak;
    string myString;
    string line;
    for (int i = 0 ; i < 2 ; i++){ 
      myfile.ignore(1000, '\n');
    }
    while (getline(myfile,line)){
      
      stringstream ss(line);
      getline(ss,Fameli1, ',');
      F1=stod(Fameli1);
      getline(ss,Fameli2 , ',');
      F2=stod(Fameli2);
      getline(ss, Dey, ',');
      De=stod(Dey);
      getline(ss, Faspa, ',');
      Fas=stod(Faspa);
      getline(ss, Samera, ',');
      Sa=stod(Samera);
      getline(ss, Shabandar, ',');
      Shab=stod(Shabandar);
      getline(ss, Hakeshti, ',');
      Hak=stod(Hakeshti);
      
      
     
      Famel1.push_back(F1);
      Famel2.push_back(F2);
      Dey1.push_back(De);
      Faspa1.push_back(Fas);
      Samera1.push_back(Sa);
      Shabandar1.push_back(Shab);
      Hakeshti1.push_back(Hak);

    }
 

  }
  int i;
  for ( i=0; i<5;i++){
    days.push_back(i);
  }
  
  int n=Famel1.size();
  cout<<"This the size of our vector:"<<endl;
  cout<<n<<endl;
  
  auto gr1 = new TGraph(n,&days[0],&Famel1[0]);
  auto gr2 = new TGraph(n, &days[0], &Famel2[0]);
  auto gr3= new TGraph(n, &days[0], &Dey1[0]);
  auto gr4= new TGraph(n, &days[0], &Faspa1[0]);
  auto gr5= new TGraph(n, &days[0], &Samera1[0]);
  auto gr6= new TGraph(n, &days[0], &Shabandar1[0]);
  auto gr7=new TGraph(n, &days[0], &Hakeshti1[0]);
  auto mg = new TMultiGraph("mg","mg");
  mg->SetTitle("Stock market analysis; Days; Variations");
  mg->Add(gr1);
  mg->Add(gr2);
  mg->Add(gr3);
  mg->Add(gr4);
  mg->Add(gr5);
  mg->Add(gr6);
  mg->Add(gr7);
  mg->Draw("apl");
  
  mg->Write();

  
  
  f.Close();
  

}

void file(){
  string ourfile={"Shahin.csv"};
  Finance(ourfile);
}
