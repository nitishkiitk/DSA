
// We define super digit of an integer  using the following rules:

// Given an integer, we need to find the super digit of the integer.

// If x  has only 1 digit, then its super digit is .
// Otherwise, the super digit of x is equal to the super digit of the sum of the digits of .
int superDigit(string n, int k) {
    if(n.length()==1 && k==1){
        return stoi(n);
    }
    long long int len=n.length();
    long long int sum=0;
    for(long long int j=0;j<len;j++){
        sum=sum + (n[j]-'0');
    }
    sum=sum*k;
    k=1;
    return superDigit(to_string(sum), k);
}