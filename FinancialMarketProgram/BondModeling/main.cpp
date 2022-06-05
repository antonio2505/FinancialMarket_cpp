#include <iostream>
#include <string>

class BondModel{
private:
    std::string compName; //company Name that issues or the issuer
    double principal;
    double coupon;
    int timePeriod;
    
public:
    BondModel(std::string n, double p, double c, int t);
    BondModel(const BondModel &v);
    BondModel &operator=(const BondModel &v);
    ~BondModel();
    
    double InterestRate();

};


BondModel::BondModel(std::string n, double p, double c, int t)
: compName(n), principal(p), coupon(c), timePeriod(t) {
    
}
BondModel::BondModel(const BondModel &v) 
 : compName(v.compName),
   principal(v.principal),
   coupon(v.coupon),
   timePeriod(v.timePeriod){
    
}
BondModel &BondModel::operator=(const BondModel &v){
    if(this!=&v){
        this->compName=v.compName;
        this->coupon =v.coupon;
        this->principal=v.principal;
        this->timePeriod=v.timePeriod;
        
    }
    return *this;
}

BondModel::~BondModel(){
    
}

double BondModel::InterestRate(){
    
    return coupon / principal;
}




int main(){
    
    std::string issuer{};
    double coupon{};
    double principal{};
    int period{};
    
    std::cout<<"Enter the Issuer Name: ";
    std::cin>>issuer;
    std::cout<<"Enter the Principal: ";
    std::cin>>principal;
    std::cout<<"Enter the coupon: ";
    std::cin>>coupon;
    std::cout<<"Enter the Period: ";
    std::cin>>period;
    std::cout<<std::endl;
    
    BondModel bond(issuer,principal,coupon,period);
    
    double result = bond.InterestRate();
    std::cout << "reading information for bond issued by " << issuer <<std::endl;
    std::cout<<std::endl;
    std::cout << "the internal rate of return is: " << result*100 <<"% on "<<period<<" years"<<std::endl;

    std::cout<<std::endl;
    return 0;
}