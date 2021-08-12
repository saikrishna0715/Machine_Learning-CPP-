#include<iostream>
#include<vector>
using namespace std;

double par_dm(const vector<int>& x,const vector<int>&y,const vector<float>& y_pred){
    double temp = 0.0;
    for(int i=0;i<x.size();i++){
        temp += (x[i]*(y[i]-y_pred[i]));
    }
    return temp;
}

double par_db(const vector<int>& x,const vector<int>&y,const vector<float>& y_pred){
    double temp = 0.0;
    for(int i=0;i<x.size();i++){
        temp += (y[i]-y_pred[i]);
    }
    return temp;
}

void Ypred(const vector<int>& x,const vector<int>& y,vector<float>& y_pred,const float& m_curr,const float& b_curr){
    for(int i=0;i<y_pred.size();i++){
        y_pred[i] = (x[i]*m_curr)+b_curr;
    }
}

void grad_des(const vector<int>& x,const vector<int>&y,int iteration,float learn_rate){
    int len = x.size();
    vector<float> y_predicted(len,0);
    float m_curr = 0.0,b_curr = 0.0;
    float dm=0,db=0;
    for(int i=1;i<=iteration;i++){
        Ypred(x,y,y_predicted,m_curr,b_curr);
        dm = -(2.0/len)*par_dm(x,y,y_predicted);
        db = -(2.0/len)*par_db(x,y,y_predicted);
        m_curr -= learn_rate*dm;
        b_curr -= learn_rate*db;
    }
    cout<<"The Coeff is "<<m_curr<<"\nThe Intercept is "<<b_curr;
}

int main(){
    vector<int> x;
    vector<int> y;
    grad_des(x,y,1000,0.03);
}
