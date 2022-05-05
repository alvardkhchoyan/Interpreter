#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>


void tip_(  std::string );
void read ( std::string );
void int_( std::string );
void float_( std::string );
void str_( std::string );
void bool_( std::string );
int popox_name( char );
void frik_( std::string );
void gorc( std::string );       
void print( std::string );      
void payman( std::string );
bool hamemat( std::string, std::string, char );
int mat_( int, int, char );

std::map < char, int > imap;
std::map < char, float > fmap;
std::map < char, std::string > smap;
std::map < char, std::string > bmap;

void translate( )
{
        std::fstream newfile;
        std::string str;
        newfile.open( "inter.txt" );    
        if( newfile.is_open () ){
                while ( getline ( newfile, str ) )
                {
                        read( str );
                }
                newfile.close();
        }
        else { 
                std::cout << "fail is not open" << std::endl;
        }
}




int main( )
{
        translate();
}




void read( std::string str )
{
        tip_( str );
}

void tip_( std::string nstr )
{

        gorc( nstr );
        if( nstr[0] == 'p' ){
                print( nstr );
        }
        if( nstr[0] == 'a' ){
                payman(nstr);
        }
        if( nstr[0] == 'f' ){
                frik_(nstr);
        }

        switch( nstr[0] ){
                case 'i': int_( nstr );
                          break;
                case 'd': float_( nstr );
                          break;
                case 's': str_( nstr );
                          break;
                case 'b': bool_( nstr );
                          break;
        }
}
void int_( std::string str )
{
        char name;
        std::string nstr;
        int count = 0;
        for( int i = 0; i < str.length(); ++i ){
                while( str[i] != ' ' ){
                        nstr += str[i];
                        ++count;
                        ++i;
                }
                if( nstr != "itip" ){
                        std::cout << " ERROR \n  popoxakani tipi mej sxal ka \n ";
                        exit(0);
                }
                ++i;
                break;
        }
        if( nstr == "itip" ){                                                           
                nstr = "";
                for( int i = count; i < str.length(); ++i ){
                        ++count;
                        if( str[i] != ' ' ){
                                if( str[i] >= 'a' && str[i] <= 'z' ){
                                        int n = popox_name( str[i] );
                                        if( n == 1 ){
                                                std::cout << " ERROR \n ka nman anunov popoxakan ";
                                                exit(0);
                                        }
                                        if( n == 0 ){
                                                name = str[i];
                                                imap[name];
                                        }    
                                }
                                else {
                                        std::cout << "ERROR \n popoxakani anun@ sxal e haytararvac ";
                                        exit(0);
                                }
                                break;
                        }
                }

        }  
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] == ':'){ return;}
                        if( str[i] != '~' ){
                                std::cout << " ERROR \n veragrum@ sxal e katarvac \n ";
                                exit(0);
                        }
                        if( str[i] == '~' ){
                                break;
                        }
                }
        }

        int num1;
        int num2;
        char ch;
        int count1 = 0;
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' '){
                        if( str[i] >= 48 && str[i] <= 57){
                                num1 = num1 * 10;
                                num1 = str[i] - 48;
                        }
                        else{
                                std::cout << " ERROR \n not integer";
                                exit(0);
                        }
                        break;
                }
        }
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' '){
                        if( str[i] == ':' ){
                                imap[name] = num1;
                                return;
                        }
                        else break;
                }
        }
        --count;
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' '){
                        if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' ){       
                                ++count1;
                                ch = str[i];
                        }
                        else {
                                std::cout << " ERROR \n chka nman gorcoxutyun ";
                                exit(0);
                        }
                        break;
                }
        }
        if( count1 == 1 ){
                for( int i = count; i < str.length(); ++i ){
                        ++count;
                        if( str[i] != ' ' ){
                                if( str[i] >= 48 && str[i] <= 57){
                                        num2 = num2 * 10;
                                        num2 = str[i] - 48;
                                }
                        }
                }
                for( int i = count; i < str.length(); ++i ){   
                        ++count;
                        if( str[i] != ' '){
                                if( str[i] == ':'){
                                        return;
                                }
                                else {
                                        std::cout << " ERROR \n chka : ";
                                        exit(0);
                                }   
                        }
                }   

                int n = mat_( num1, num2, ch);
                imap[name] = n;
        }

}


void float_( std::string str )
{

        char name;
        std::string nstr;
        int count = 0;
        int n = 0;
        for( int i = 0; i < str.length(); ++i ){
                while( str[i] != ' ' ){
                        nstr += str[i];
                        ++count;
                        ++i;
                }
                if( nstr != "dtip" ){
                        std::cout << " ERROR \n  popoxakani tipi mej sxal ka \n ";
                        exit(0);
                }
                ++i;
                break;
        }
        if( nstr == "dtip" ){                                                               
                nstr = "";
                for( int i = count; i < str.length(); ++i ){
                        ++count;
                        if( str[i] != ' ' ){
                                if( str[i] >= 'a' && str[i] <= 'z' ){
                                        int n = popox_name( str[i] );
                                        if( n == 1 ){
                                                std::cout << " ERROR \n ka nman anunov popoxakan ";
                                                exit(0);
                                        }
                                        if( n == 0 ){
                                                name = str[i];
                                                fmap[name]; 
                                        } 
                                }        

                                else{
                                        std::cout << " ERROR \n popoxakani anun@ sxal e haytararvac ";
                                        exit(0);
                                }
                                break;
                        }    
                }
        }
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] != '~' ){
                                std::cout << " ERROR \n veragrum@ sxal e katarvac \n ";
                                exit(0);
                        }
                        if( str[i] == '~' ){
                                break;
                        }
                }
        }

        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ':'){
                        if( str[i] != ' ' ){
                                if( str[i] >= '0' && str[i] <= '9' ){
                                        nstr += str[i];
                                        continue;
                                }
                                else if( str[i] == '.' ){
                                        nstr += str[i];
                                        ++n;
                                        continue;
                                }
                                if( ( n > 1 ) || ( str[i] < '0' || str[i] > '9' ) ){
                                        std::cout << " ERROR \n sxal arjeq ";
                                        exit(0);
                                }
                                break;
                        }
                }
        }
        if( nstr.length() != 0 ){
                float number = stof( nstr );
                fmap[name] = number;
        }    
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] == ':' ){
                                return;
                        }
                        else {
                                std::cout << " ERROR \n : chka ";
                                exit(0);
                        }
                        break;
                }
        }
}




void str_( std::string str )
{
        char name;
        std::string nstr;
        int count = 0;
        int n = 0;
        for( int i = 0; i < str.length(); ++i ){
                while( str[i] != ' ' ){
                        nstr += str[i];
                        ++count;
                        ++i;
                }
                if( nstr != "stip" ){
                        std::cout << " ERROR \n  popoxakani tipi mej sxal ka \n ";
                        exit(0);
                }
                ++i;
                break;
        }
        if( nstr == "stip" ){
                nstr = "";
                for( int i = count; i < str.length(); ++i ){
                        ++count;
                        if( str[i] != ' ' ){
                                if( str[i] >= 'a' && str[i] <= 'z' ){

                                        int n = popox_name( str[i] );
                                        if( n == 1 ){
                                                std::cout << " ERROR \n ka nman anunov popoxakan ";
                                                exit(0);
                                        }
                                        if( n == 0 ){
                                                name = str[i];
                                                smap[name];
                                        }
                                }

                                else{
                                        std::cout << "ERROR \n popoxakani anun@ sxal e haytararvac ";
                                        exit(0);
                                }
                                break;
                        }
                }
        }
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] == ':' ){
                                break;
                        }

                        if( str[i] != '~' ){
                                std::cout << " ERROR \n veragrum@ sxal e katarvac \n ";
                                exit(0);
                        }
                        if( str[i] == '~' ){
                                break;
                        }
                }
        }

        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ':' ){
                        if( str[i] != ' ' ){
                                nstr += str[i];
                        }
                }
        }
        if( nstr.length() != 0 ){
                smap[name] = nstr;
        }
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] == ':' ){
                                return;
                        }
                        else{
                                std::cout << " ERROR \n : chka ";
                                exit(0);
                        }
                        break;
                }
        }
}     



void bool_( std::string str )
{
        char name;
        std::string nstr;
        int count = 0;
        int n = 0;
        for( int i = 0; i < str.length(); ++i ){
                while( str[i] != ' ' ){
                        nstr += str[i];
                        ++count;
                        ++i;
                }
                if( nstr != "btip" ){
                        std::cout << " ERROR \n  popoxakani tipi mej sxal ka \n ";
                        exit(0);
                }
                ++i;
                break;
        }
        if( nstr == "btip" ){
                nstr = "";
                for( int i = count; i < str.length(); ++i ){
                        ++count;
                        if( str[i] != ' ' ){
                                if( str[i] >= 'a' && str[i] <= 'z' ){

                                        int n = popox_name( str[i] );
                                        if( n == 1 ){
                                                std::cout << " ERROR \n ka nman anunov popoxakan ";
                                                exit(0);
                                        }

                                        if( n == 0 ){
                                                name = str[i];
                                                bmap[name];
                                        }
                                }

                                else{
                                        std::cout << "ERROR \n popoxakani anun@ sxal e haytararvac ";
                                        exit(0);
                                }
                                break;
                        }
                }
        }
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] == ':' ){
                                break;
                        }

                        if( str[i] != '~' ){
                                std::cout << " ERROR \n veragrum@ sxal e katarvac \n ";
                                exit(0);
                        }
                        if( str[i] == '~' ){
                                break;
                        }
                }
        }

        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ':' ){
                        if( str[i] != ' ' ){
                                nstr += str[i];
                        }
                }
        }
        if( nstr == "false" || nstr == "true" ){
                bmap[name] = nstr;
        }
        else{    
                std::cout << " ERROR \n sxal arjeq ";
                exit(0);
        }        
        for( int i = count; i < str.length(); ++i ){
                ++count;
                if( str[i] != ' ' ){
                        if( str[i] == ':' ){
                                return;
                        }
                        else{
                                std::cout << " ERROR \n : chka ";
                                exit(0);
                        }
                        break;
                }
        }

}

int popox_name( char str )
{
        if( imap.count ( str ) == 1 )
        {
                return 1;
        }
        else if( fmap.count( str ) == 1 )
        {
                return 1;
        }
        else if( smap.count( str ) == 1 )
        {
                return 1;
        }
        else if( bmap.count( str ) == 1 )
        {
                return 1;
        }
        else
                return 0;
}

void print( std::string str )
{
        int i = 0;
        int j = 0;
        int count = 0;
        std::string strcmp;
        std::string  strprint = "print";
        while(str[i] == strprint[j]){
                ++i;
                ++j;
                ++count;
        }
        if(count == strprint.length()){
                count = 0;
                j = 0;
        }
        if(count != 0){
                std::cout << "error print " << std::endl;
                exit(0);
        }
        do
        {
                while(str[i] == ' '){++i;}
                if(str[i] != '<'){
                        std::cout << "error print '<' " << std::endl;
                        exit(0);
                }
                while(str[i] == '<'){
                        ++count;
                        ++i;
                }
                if(count != 2){
                        std::cout << " error << " << std::endl;
                        exit(0);
                }
                count = 0; 
                while(str[i] == ' '){++i;}
                if(str[i] >= 97 && str[i] <= 122){
                        strcmp += str[i];
                        ++i;
                }
                bool pop = popox_name(strcmp[0]);
                if(pop == 0){
                        std::cout << "error varible1 " << std::endl;
                        exit(0);
                }
                if(pop){
                        std::cout << " ";
                        if( imap.count( strcmp[0]) == 1 ){ std::cout << imap[strcmp[0]];}
                        else if( fmap.count( strcmp[0] ) == 1 ){ std::cout << fmap[strcmp[0]];}
                        else if( smap.count( strcmp[0]) == 1 ){ std::cout << smap[strcmp[0]] ;}
                        else if( bmap.count( strcmp[0]) == 1 ){ std::cout << bmap[strcmp[0]] ;}

                        pop = 0;
                }
                strcmp = ""; 
                while(str[i] == ' '){++i;}
        }while(str[i] != ':');
        if(str[i] != ':'){
                std::cout << " error :  prinq " << std::endl;
                exit(0);

        }
        ++i;
}   

int mat_( int num1, int num2, char ma )
{
        if( ma == '+')
        {
                num1 += num2;
                return num1;
        }
        if( ma == '-')
        {
                num1 -= num2;
                return num1;
        }
        if( ma == '*')
        {
                num1 *= num2;
                return num1;
        }
        if( ma == '/')
        {
                num1 /= num2;
                return num1;
        }
        if( ma == '%' )
        {
                num1 %= num2;
                return num1;
        }
}

void gorc( std::string str )
{
        int n = popox_name( str[0] );
        if( n == 0 ) { return; }
        int count = 0;
        int ka;
        int num;

        if( imap.count( str[0] ) == 1 ){
                std::string nstr;

                for( int i = 1; i < str.length(); ++i ){
                        ++count;
                        if( str[i] != ' ' ){
                                if( str[i] != '~' ){
                                        break;
                                }
                        }      
                }
                for( int i = count; i < str.length(); ++i ){
                        nstr == "";
                        ++count;
                        if( str[i] != ':' ){
                                if( str[i] != ' ' ){
                                        if( str[i] > '0' && str[i] < '9' ){
                                                nstr += str[i];
                                                imap[str[0]] = stoi(nstr);
                                        }
                                        else if( str[i] >= 'a' && str[i] <= 'z' ){
                                                ka = imap.count(str[i]);
                                                if( ka == 1 ){
                                                        imap[str[0]] = imap[str[i]];
                                                }
                                        }
                                        else{  
                                                std::cout << "ERROR \n cheq karox mnan veragrum anel:";
                                                exit(0);
                                        }        
                                }
                        }
                }
        }

}

void payman( std::string str )
{
        std::string strcmp = "";
        std::string strcmp1 = "";
        std::string str1 = "ardyoq";
        int i = 0;
        int j = 0;
        int count = 0;
        while(str[i] == str1[j]){
                ++i;
                ++j;
                ++count;
        }
        if(count == str1.length()){
                count = 0;
                j = 0;
        }
        if(count != 0){
                std::cout << " error ardyoq " << std::endl;
                exit(0);
        }
        while(str[i] != ' '){
                std::cout << "error white space" << std::endl;
                exit(0);
        }
        while(str[i] == ' '){++i;}

        if(str[i] != '('){
                std::cout << "error ardyoq '(' " << std::endl;
                exit(0);
        }
        ++i;
        while(str[i] == ' '){++i;}
        if(str[i] >= 97 && str[i] <= 122){
                strcmp += str[i];
                ++i;
        }
        while(str[i] == ' '){++i;}
        if(str[i] != '>' && str[i] != '<'){
                std::cout << "error symbol " << std::endl;
                exit(0);
        }
        char c = str[i];
        ++i;
        while(str[i] == ' '){++i;}
        if(str[i] >= 97 && str[i] <= 122){
                strcmp1 += str[i];
                ++i;
        }
        while(str[i] == ' '){++i;}
        if(str[i] != ')'){
                std::cout << " error scope ')' " << std::endl;
                exit(0);
        }
        ++i;
        bool true_false = hamemat(strcmp,strcmp1,c);
        strcmp = "";
        if(true_false){
                while(str[i] == ' '){++i;}
                if(str[i] != '{'){
                        std::cout << "error ardyoq '{' scope " << std::endl;
                        exit(0);
                }
                ++i;
                while(str[i] == ' '){++i;}
                std::string  strprint = "print";
                while(str[i] == strprint[j]){
                        ++i;
                        ++j;
                        ++count;
                }
                if(count == strprint.length()){
                        count = 0;
                        j = 0;
                }
                if(count != 0){
                        std::cout << "error print " << std::endl;
                        exit(0);
                }
                std::cout << std::endl;
                do
                {
                        while(str[i] == ' '){++i;}
                        if(str[i] != '<'){
                                std::cout << "error print '<' " << std::endl;
                                exit(0);
                        }
                        while(str[i] == '<'){
                                ++count;
                                ++i;
                        }
                        if(count != 2){
                                std::cout << " error << " << std::endl;
                                exit(0);
                        }
                        count = 0; 
                        while(str[i] == ' '){++i;}
                        if(str[i] >= 97 && str[i] <= 122){
                                strcmp += str[i];
                                ++i;
                        }
                        bool pop = popox_name(strcmp[0]);
                        if(pop == 0){
                                std::cout << "error varible1 " << std::endl;
                                exit(0);
                        }
                        if(pop){
                                if(pop){
                                        std::cout << " ";
                                        if( imap.count( strcmp[0]) == 1 ){ std::cout << imap[strcmp[0]];}
                                        else if( fmap.count( strcmp[0] ) == 1 ){ std::cout << fmap[strcmp[0]];}
                                        else if( smap.count( strcmp[0]) == 1 ){ std::cout << smap[strcmp[0]] ;}
                                        else if( bmap.count( strcmp[0]) == 1 ){ std::cout << bmap[strcmp[0]] ;}

                                        pop = 0;
                                }

                        }
                        strcmp = ""; 
                        while(str[i] == ' '){++i;}
                }while(str[i] != ':');
                if(str[i] != ':'){
                        std::cout << " error :  ardyoq " << std::endl;
                        exit(0);
                }
                ++i;
                while(str[i] == ' '){++i;}
                if(str[i] != '}'){
                        std::cout << "print } scope " << std::endl;
                        exit(0);
                }
        }   
}

bool hamemat( std::string str1, std::string str2, char gorc)
{

        if(( str1.length() == 1 ) && ( str2.length() == 1 )){
                for( int i = 0; i < str1.length(); ++i ){
                        if(( imap.count( str1[0]) == 1 ) && ( imap.count( str2[0] ) == 1 )) {
                                switch(gorc){
                                        case '>':
                                                return imap[str1[0]] > imap[str2[0]];
                                        case '<':
                                                return imap[str1[0]] < imap[str2[0]];
                                }
                        }

                        else if(( fmap.count( str1[0]) == 1 ) && ( fmap.count( str2[0] ) == 1 )) {

                                switch(gorc){
                                        case '>':
                                                return fmap[str1[0]] > fmap[str2[0]];
                                        case '<':
                                                return fmap[str1[0]] < fmap[str2[0]];
                                }

                        }
                }
        }
        else{
                switch(gorc){
                        case '>':
                                return stoi(str1) > stoi(str2);
                        case '<':
                                return stoi(str2) < stoi(str1);
                }

        }

}

void frik_( std::string str )
{
        std::string strcmp = "";
        std::string strcmp1 = "";
        std::string str1 = "frik";
        int i = 0;
        int j = 0;
        int count = 0;
        while(str[i] == str1[j]){
                ++i;
                ++j;
                ++count;
        }
        if(count == str1.length()){
                count = 0;
                j = 0;
        }
        if(count != 0){
                std::cout << "error frik " << std::endl;
                exit(0);
        }
        while(str[i] != ' '){
                std::cout << "error white space" << std::endl;
                exit(0);
        }
        while(str[i] == ' '){++i;}

        if(str[i] != '('){
                std::cout << "error frik '(' " << std::endl;
                exit(0);
        }
        ++i;
        while(str[i] == ' '){++i;}
        if(str[i] >= '0' && str[i] <= '9'){
                strcmp += str[i];
                ++i;
        }
        while(str[i] == ' '){++i;}
        if(str[i] != ')'){
                std::cout << " error scope ')' " << std::endl;
                exit(0);
        }
        ++i;
        if(stoi(strcmp)){
                strcmp = ""; 
                while(str[i] == ' '){++i;}
                if(str[i] != '{'){
                        std::cout << "error frik '{' scope " << std::endl;
                        exit(0);
                }
                ++i;
                while(str[i] == ' '){++i;}
                std::string  strprint = "print";
                while(str[i] == strprint[j]){
                        ++i;
                        ++j;
                        ++count;
                }
                if(count == strprint.length()){
                        count = 0;
                        j = 0;
                }
                if(count != 0){
                        std::cout << "error print " << std::endl;
                        exit(0);
                }
                std::cout << std::endl;
                do
                {
                        while(str[i] == ' '){++i;}
                        if(str[i] != '<'){
                                std::cout << "error print '<' " << std::endl;
                                exit(0);
                        }
                        while(str[i] == '<'){
                                ++count;
                                ++i;
                        }
                        if(count != 2){
                                std::cout << " error << " << std::endl;
                                exit(0);
                        }
                        count = 0; 
                        while(str[i] == ' '){++i;}
                        if(str[i] >= 97 && str[i] <= 122){
                                strcmp += str[i];
                                ++i;
                        }
                        bool pop = popox_name(strcmp[0]);
                        if(pop == 0){
                                std::cout << "error varible1 " << std::endl;
                                exit(0);
                        }  
                        if(pop){
                                if(pop){
                                        std::cout << " ";
                                        if( imap.count( strcmp[0]) == 1 ){ std::cout << imap[strcmp[0]];}
                                        else if( fmap.count( strcmp[0] ) == 1 ){ std::cout << fmap[strcmp[0]];}
                                        else if( smap.count( strcmp[0]) == 1 ){ std::cout << smap[strcmp[0]] ;}
                                        else if( bmap.count( strcmp[0]) == 1 ){ std::cout << bmap[strcmp[0]] ;}

                                        pop = 0;
                                }
                        } 

                        strcmp = ""; 
                        while(str[i] == ' '){++i;}
                }while(str[i] != ':');
                if(str[i] != ':'){
                        std::cout << " error :  frik " << std::endl;
                        exit(0);
                }
                ++i;
                while(str[i] == ' '){++i;}
                if(str[i] != '}'){
                        std::cout << "print } scope " << std::endl;
                        exit(0);
                }
        } 
}
