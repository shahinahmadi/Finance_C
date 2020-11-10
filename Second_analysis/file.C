#include<iostream>
#include <cstdio>
#include "TGraph.h"
#include<vector>
#include <fstream>
#include <string>

using namespace std;


void Finance(string filename){
  vector<double>price;
  vector<double>growth;

  ifstream myfile(filename);
  if (myfile.is_open()){
    string Stuck_name, Stuck_value, Stuck_growth;
    double Stuck_v,Growth;
    string myString;
    string line;
    for (int i = 0 ; i < 2 ; i++){ 
      myfile.ignore(1000, '\n');
    }
    while (getline(myfile,line)){
      
      stringstream ss(line);
       getline(ss, Stuck_name, ',');
      getline(ss,Stuck_value, ',');
      Stuck_v=stod(Stuck_value);
      getline(ss, Stuck_growth, ',');
      Growth=stod(Stuck_growth);
      
      cout<<Growth<<endl;
      price.push_back(Stuck_v);
      growth.push_back(Growth);

    }
 

  }
  int n=price.size();
  cout<<"This the size of our vector:"<<endl;
  cout<<n<<endl;
  auto gr = new TGraph(n,&price[0],&growth[0]);
  gr->Draw();
  

}

void file(){
  string ourfile={"/home/shahin/Desktop/Finance2.csv"};
  Finance(ourfile);
}
