#include <iostream>
#include <string>



class FondamentalAnalyse{
    
private:
    std::string m_tickers;
    double m_prices;
    double m_dividend;
    double m_earningEstimate;
    int NumOfShares;
    double bookValues;
    double earnings;
    double assets;
    double epsGrowth;
    double liabilitiesTangible;
    double m_netIncome;
    double m_shareholdersEquity;
    
public:
    FondamentalAnalyse(std::string &m_tikers, double m_prices, double dividend);
    ~FondamentalAnalyse();
    FondamentalAnalyse(const FondamentalAnalyse &v);
    FondamentalAnalyse &operator=(const FondamentalAnalyse &v);
    
    void setNumOfShares(int n);
    void setEarnings(double val);
    void setExpectedEarning(double val);
    void setBookValue(double val);
    void setAssets(double val);
    void setLiabilitiesTangible(double val);
    void setepsGrowth(double val);
    void setNetIncome(double val);
    void setShareHolderEquity(double val);
    
    double PE();
    double ForwardPE();
    double Bookvalue();
    double PriceToBookRatio();
    double PriceEarningsToGrowth();
    double ReturnsOnEquity();
    double GetDividend();
    
    
};


FondamentalAnalyse::FondamentalAnalyse(std::string &tickers, double prices, double dividend)
 : m_tickers(tickers),
    m_prices(prices),
    m_dividend(dividend),
    m_earningEstimate(0),
    NumOfShares(0),
    bookValues(0),
    earnings(0),
    assets(0),
    epsGrowth(0),
    liabilitiesTangible(0),
    m_netIncome(0),
    m_shareholdersEquity(0){
        
}
 
FondamentalAnalyse::~FondamentalAnalyse(){
    
}

FondamentalAnalyse::FondamentalAnalyse(const FondamentalAnalyse &v)
 : m_tickers(v.m_tickers),
    m_prices(v.m_prices),
    m_dividend(v.m_dividend),
    m_earningEstimate(v.m_earningEstimate),
    NumOfShares(v.NumOfShares),
    bookValues(v.bookValues),
    earnings(v.earnings),
    assets(v.assets),
    epsGrowth(v.epsGrowth),
    liabilitiesTangible(v.liabilitiesTangible),
    m_netIncome(v.m_netIncome),
    m_shareholdersEquity(v.m_shareholdersEquity){
    
}

FondamentalAnalyse &FondamentalAnalyse::operator=(const FondamentalAnalyse &v){
    
    if(this!=&v){
    this->m_tickers=v.m_tickers;
    this->m_prices=v.m_prices;
    this->m_dividend=v.m_dividend;
    this->m_earningEstimate=v.m_earningEstimate;
    this->NumOfShares=v.NumOfShares;
    this->bookValues=v.bookValues;
    this->earnings=v.earnings;
    this->assets=v.assets;
    this->epsGrowth=v.epsGrowth;
    this->liabilitiesTangible=v.liabilitiesTangible;
    this->m_netIncome=v.m_netIncome;
    this->m_shareholdersEquity = v.m_shareholdersEquity;
        
    }
    return *this;
}

double FondamentalAnalyse::PE(){
    
    return (m_prices*NumOfShares)/earnings;
}
double FondamentalAnalyse::ForwardPE(){
    
    return (m_prices*NumOfShares)/ m_earningEstimate;
}

double FondamentalAnalyse::ReturnsOnEquity(){
    
    return m_netIncome / m_shareholdersEquity;
}

double FondamentalAnalyse::GetDividend(){
    
    return m_dividend;
}

double FondamentalAnalyse::Bookvalue(){
    
    return bookValues;
}
double FondamentalAnalyse::PriceToBookRatio(){
    
    return (m_prices*NumOfShares)/(assets - liabilitiesTangible);
}
double FondamentalAnalyse::PriceEarningsToGrowth(){
    
    return PE() / epsGrowth;
}



void FondamentalAnalyse::setNumOfShares(int n){
    
    NumOfShares = n;
}

void FondamentalAnalyse::setEarnings(double val){
    
    earnings=val;
}
void FondamentalAnalyse::setExpectedEarning(double val){
    
    m_earningEstimate = val;
}
void FondamentalAnalyse::setBookValue(double val){
    
    bookValues =val;
}
void FondamentalAnalyse::setAssets(double val){
    
    assets=val;
}
void FondamentalAnalyse::setLiabilitiesTangible(double val){
    
    liabilitiesTangible = val;
}
void FondamentalAnalyse::setepsGrowth(double val){
    
    epsGrowth=val;
}
void FondamentalAnalyse::setNetIncome(double val){
    
    m_netIncome = val;
}
void FondamentalAnalyse::setShareHolderEquity(double val){
    
    m_shareholdersEquity=val;
}


int main(){
    
    double stockPrice{0};
    double dividend{0};
    std::string stock{""};
    double asset{0};
    double bv{0};
    double earnings{0};
    double eps{0};
    double expearning{0};
    double liability{0};
    double netincome{0};
    double holders{0};
    int numshare{0};
    
    std::cout<<"############ Fondamental Analysis ##########"<<std::endl;
    std::cout<<"========================================================="<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Enter Stock Name: ";
    std::cin>>stock;
    std::cout<<"Enter "<<stock<<" Price: ";
    std::cin>>stockPrice;
    std::cout<<"Enter "<<stock<<" Dividend: ";
    std::cin>>dividend;
    
    FondamentalAnalyse fa(stock,stockPrice,dividend);
    
    std::cout<<"All Value are in Million,"<<std::endl;
    std::cout<<"==========================================================="<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Enter "<<stock<<" Assets                    : ";
    std::cin>>asset;
    std::cout<<"Enter "<<stock<<" BookValue                 : ";
    std::cin>>bv;
    std::cout<<"Enter "<<stock<<" Earnings                  : ";
    std::cin>>earnings;
    std::cout<<"Enter "<<stock<<" EpsGrowth                 : ";
    std::cin>>eps;
    std::cout<<"Enter "<<stock<<" Expected Earnings         : ";
    std::cin>>expearning;
    std::cout<<"Enter "<<stock<<" Liabilities and Intangible: ";
    std::cin>>liability;
    std::cout<<"Enter "<<stock<<" Net Income                : ";
    std::cin>>netincome;
    std::cout<<"Enter "<<stock<<" Number of Share           : ";
    std::cin>>numshare;
    std::cout<<"Enter "<<stock<<" Share Holders Equity      : ";
    std::cin>>holders;
    
    fa.setAssets(asset);
    fa.setBookValue(bv);
    fa.setEarnings(earnings);
    fa.setepsGrowth(eps);
    fa.setExpectedEarning(expearning);
    fa.setLiabilitiesTangible(liability);
    fa.setNetIncome(netincome);
    fa.setNumOfShares(numshare);
    fa.setShareHolderEquity(holders);
    
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"P/E of "<<stock<<" is                    : "<<fa.PE()/1000<<std::endl;
    std::cout<<"Forward P/E of "<<stock<<" is            : "<<fa.ForwardPE()/1000<<std::endl;
    std::cout<<"Book Value of "<<stock<<" is             : "<<fa.Bookvalue()<<std::endl;
    std::cout<<"Price to book of "<<stock<<" is          : "<<fa.PriceToBookRatio()<<std::endl;
    std::cout<<"Price Earning to Growth of "<<stock<<" is: "<<fa.PriceEarningsToGrowth()<<std::endl;
    std::cout<<"Return On Equity of "<<stock<<" is       : "<<fa.ReturnsOnEquity()<<std::endl;
    std::cout<<"Dividend of "<<stock<<" is               : "<<fa.GetDividend()<<std::endl;
    std::cout<<"============================================================="<<std::endl;
    
    
    std::cout<<std::endl;
    return 0;
}