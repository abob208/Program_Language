# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <vector>
# include <string>
using namespace std;
enum TokenType { IDENT = 34512, SIGN = 87232, NUM = 29742, QUIT = 88888, SS = 456465 } ;
struct Token {
  string name ;
  int column ;
  int line ;
  TokenType type ;
};

struct Variable {
  string name ;
  float value ;
  bool isfloat ;
};
class Parser {
  public :
  void Command( Token token ) ;
  void IDlessArithExpOrBexp() ;
  bool BooleanOprator() ;
  void NOT_ID_StartArithExpOrBexp() ;
  void NOT_ID_StartArithExp() ;
  void NOT_ID_StartTerm() ;
  void NOT_ID_StartFactor() ;
  void ArithExp() ;
  void Term() ;
  void Factor( string pretoken ) ;
  void Calculation() ;
  void CAL_IDlessArithExpOrBexp( float & value ) ;
  bool CAL_BooleanOprator( Token & token ) ;
  void CAL_NOT_ID_StartArithExpOrBexp( float & value ) ;
  void CAL_NOT_ID_StartArithExp( float & value ) ;
  void CAL_NOT_ID_StartTerm( float & value ) ;
  void CAL_NOT_ID_StartFactor( float & value ) ;
  void CAL_ArithExp( float & value ) ;
  void CAL_Term( float & value ) ;
  void CAL_Factor( float & value ) ;
  void Clear() ;
  void Print() ;
  bool Defined( string name ) ;
  float IDvalue( string ID ) ;
  void Havedot( string num ) ;
  private :
  vector<Token> mtokenList ;
  vector<Variable> mVariableList ;
  bool mOprator ;
  bool mYesorno ;
  bool mChange ;
  bool misfloat ;
  Token mnexttoken ;
  float mvalue ;
  int mindex ;
};
class StringProccess {
  public :
  Token Peektoken() ;
  Token Gettoken( Token token ) ;
  char GetNextChar() ;
  char GetNextNonSpaceChar() ;
  string GetCaseOneToken( char a ) ;
  string GetCaseTwoToken( char a ) ;
  string GetCaseThreeToken( char a ) ;
  bool Case1( char a ) ;
  bool Case2( char a ) ;
  bool Case3( char b ) ;
  bool IsNum( char a ) ;
};

int gline = 1 ;              // 「下一個要讀進來的字元」所在的line number
int gcol = 0 ;  

int main() {
  int uTestNum = 0 ;
  scanf( "%d", &uTestNum ) ;
  Parser parser ;
  char garbage = '\0' ;
  StringProccess scanner ;
  Token token ;
  bool docalculation = true ;
  bool quit = false ;
  printf( "Program starts...\n" ) ;
  try {
    token = scanner.Peektoken() ;
  } // try
  catch ( char a ) {
    cout << "> Unrecognized token with first char : '" << a << "'\n" ;
    while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
    docalculation = false ;
    garbage = '\0' ;
  } // catch
  
  while ( token.name != "EOF"  && !quit ) {
    try {
      if ( docalculation )
        parser.Command( token ) ;
    } // try
    catch ( char a ) {
      cout << "> Unrecognized token with first char : '" << a << "'\n" ;
      while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
      docalculation = false ;
      garbage = '\0' ;
    } // catch
    catch ( string error ) {
      cout << "> Unexpected token : '" << error << "'\n" ;
      while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
      docalculation = false ;
      garbage = '\0' ;
    } // catch
    catch ( Token token ) {
      cout << "> Undefined identifier : '" << token.name << "'\n" ;
      while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
      docalculation = false ;
      garbage = '\0' ;
    } // catch
    catch ( int a ) {
      cout << "> Error\n" ;
      while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
      docalculation = false ;
      garbage = '\0' ;
    } // catch

    try {
      if ( docalculation )
        parser.Calculation() ;
    } // try
    catch ( int a ) {
      cout << "> Error\n" ;
      while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
      docalculation = false ;
      garbage = '\0' ;
    } // catch

    if ( token.name != "quit" && docalculation )
      parser.Print() ;
    parser.Clear() ;
    if ( token.name == "quit" )
      quit = true ;

    docalculation = true ;
    garbage = '\0' ;
    try {
      if ( !quit )
        token = scanner.Peektoken() ;
    } // try
    catch ( char a ) {
      cout << "> Unrecognized token with first char : '" << a << "'\n" ;
      while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
      docalculation = false ;
      garbage = '\0' ;
    } // catch

    garbage = '\0' ;
  } // while(
  /*
  vector<Token> mmtokenList ;
  Token token = StringProccess::mnexttoken();
  while ( token.name != "EOF" ) {
    mtokenList.push_back( token ) ;
    token = StringProccess::mnexttoken();
  } // while()
  */

  /*
  for ( int i = 0 ; i < mtokenList.size() ; i++ )
    cout << mtokenList[i].name <<  "(" << mtokenList[i].line << "," << mtokenList[i].column << ")" ;
  */
} // main()

void Parser::Havedot( string num ) {
  for ( int i = 0 ; i < num.size() ; i++ ) {
    if ( num[i] == '.' )
      misfloat = true ;
  } // for
} // Parser::Havedot()

void Parser::Print() {
  int a = ( int ) mvalue ;
  if ( !mOprator ) {
    if ( !misfloat )
      printf( "> %d\n", a ) ;
    else if ( misfloat )
      printf( "> %1.3f\n", mvalue ) ;
  } // if
  else if ( mOprator ) {
    if ( mYesorno )
      cout << "> true\n" ;
    else if ( !mYesorno )
      cout << "> false\n" ;
  } // else if
  
    
} // Parser::Print()

void Parser::Clear() {
  // mvalue = 0 ;
  mindex = 0 ;
  mChange = false ;
  misfloat = false ;
  mtokenList.clear() ;
} // Parser::Clear()

float Parser::IDvalue( string ID ) {
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( ID == mVariableList[i].name ) {
      misfloat = mVariableList[i].isfloat ;
      return mVariableList[i].value ;
    } // if
  } // for
  
  return 0 ;
} // Parser::IDvalue()

void Parser::Calculation() {
  misfloat = false ;
  mOprator = false ;
  mYesorno = false ;
  mChange = false ;
  mindex = 0 ;
  StringProccess scanner ;
  string tempID ;
  Variable variable ;
  mnexttoken = mtokenList[mindex] ;
  // cout << mtokenList.size() ;
  // cout << mnexttoken.name ;
  if ( mnexttoken.name == "EOF" ) {
    return ;
  } // if
  
  if ( mnexttoken.name == "quit" ) {
    printf( "> Program exits..." ) ;
    return ;
  } // if

  if ( mnexttoken.type == IDENT ) {
    tempID = mnexttoken.name ;
    mnexttoken.name = "\0" ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
    
    
    if ( mnexttoken.name == ":=" ) {
      mChange = true ;
      mnexttoken.name = "\0" ;
      CAL_ArithExp( mvalue ) ;
    } // if
    else {
      mvalue = IDvalue( tempID ) ;
      CAL_IDlessArithExpOrBexp( mvalue ) ;
    } // else

    // cout << mnexttoken.name ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if

    if ( mnexttoken.name == ";" ) {
      if ( Defined( tempID ) && mChange ) {
        for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
          if ( tempID == mVariableList[i].name ) {
            mVariableList[i].value = mvalue ;
            mVariableList[i].isfloat = misfloat ;
          } // if
        } // for
      } // if
      else {
        variable.name = tempID ;
        variable.value = mvalue ;
        variable.isfloat = misfloat ;
        mVariableList.push_back( variable ) ;
      } // else

      mnexttoken.name = "\0" ;
      // cout << "great" ;
      return ;
    }  // if
  } // if
  else {
    CAL_NOT_ID_StartArithExpOrBexp( mvalue ) ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if

    if ( mnexttoken.name == ";" ) {
      mnexttoken.name = "\0" ;
      // cout << "great" ;
      return ;
    }  // if

  } // else
} // Parser::Calculation()

void Parser::CAL_ArithExp( float & value ) {
  StringProccess scanner ;
  Token sign ;
  // int value ; 
  CAL_Term( value ) ;
  // cout << value ;
  float value2 ;
  if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
    mindex++ ;
    mnexttoken = mtokenList[mindex] ;
  } // if 

  while ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
    sign = mnexttoken ;
    mnexttoken.name = "\0" ;

    CAL_Term( value2 ) ;
    // cout << value2 ;
    if ( sign.name == "+" )
      value = value + value2 ;
    else if ( sign.name == "-" )
      value = value - value2 ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
  } // while()
} // Parser::CAL_ArithExp()

void Parser::CAL_IDlessArithExpOrBexp( float & value ) {
  StringProccess scanner ;
  // mnexttoken = StringProccess::mnexttoken() ;
  Token sign ;
  float value2 = 0 ;
  // value = 0 ;
  // int value ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" || 
          mnexttoken.name == "*" || mnexttoken.name == "/" ) {
    
    if ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
      sign = mnexttoken ;
      mnexttoken.name = "\0" ;
      CAL_Term( value2 ) ;
      if ( sign.name == "+" )
        value = value + value2 ;
      else if ( sign.name == "-" )
        value = value - value2 ;
    } // if
    else if ( mnexttoken.name == "*" || mnexttoken.name == "/" ) {
      sign = mnexttoken ;
      mnexttoken.name = "\0" ;
      CAL_Factor( value2 ) ;
      if ( sign.name == "*" )
        value = value * value2 ;
      else if ( sign.name == "/" ) {
        if ( value2 == 0 )
          throw 0 ;
        value = value / value2 ;
      } // else if
    } // else if

    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
  } // while
  
  Token oprator ;
  if ( CAL_BooleanOprator( oprator ) ) {
    mOprator = true ;
    CAL_ArithExp( value2 ) ;
    if ( oprator.name == "=" ) {
      if ( value == value2 ) {
        mYesorno = true ;
      } // if
    } // if
    else if ( oprator.name == "<>" ) {
      if ( value != value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == ">" ) {
      if ( value > value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == "<" ) {
      if ( value < value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == ">=" ) {
      if ( value >= value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == "<=" ) {
      if ( value <= value2 ) {
        mYesorno = true ;
      } // if
    } // else if

  } // if
  
} // Parser::CAL_IDlessArithExpOrBexp()


void Parser::CAL_Term( float & value ) {
  StringProccess scanner ;
  Token sign ;
  float value2 = 0 ;
  CAL_Factor( value ) ;
  // cout << value << "\n" ;
  // cout << mnexttoken.name << "\n" ;
  if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
    mindex++ ;
    mnexttoken = mtokenList[mindex] ;
  } // if

  // cout << mnexttoken.name << "\n" ;
  while ( mnexttoken.name == "*" || mnexttoken.name == "/" ) {
    sign = mnexttoken ;
    mnexttoken.name = "\0" ;
    CAL_Factor( value2 ) ;
    // cout << value << "   " << mvalue ;
    if ( sign.name == "*" )
      value = value * value2 ;
    else if ( sign.name == "/" ) {
      if ( value2 == 0 )
        throw 0 ;
      value = value / value2 ;
    } // else if

    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
  } // while
} // Parser::CAL_Term()

bool Parser::CAL_BooleanOprator( Token & oprator ) {
  StringProccess scanner ;
  if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
    mindex++ ;
    mnexttoken = mtokenList[mindex] ;
  } // if

  if ( mnexttoken.name == "=" || mnexttoken.name == "<>" || mnexttoken.name == ">" || 
       mnexttoken.name == "<" || mnexttoken.name == ">=" || mnexttoken.name == "<=" ) {
    oprator = mnexttoken ;
    mnexttoken.name = "\0" ;
    return true ;
  } // if
  
  return false ;
} // Parser::CAL_BooleanOprator()

void Parser::CAL_NOT_ID_StartArithExpOrBexp( float & value ) {
  CAL_NOT_ID_StartArithExp( value ) ;
  float value2 = 0 ;
  Token oprator ;
  if ( CAL_BooleanOprator( oprator ) ) {
    mOprator = true ;
    CAL_ArithExp( value2 ) ;
    if ( oprator.name == "=" ) {
      if ( value == value2 ) {
        mYesorno = true ;
      } // if
    } // if
    else if ( oprator.name == "<>" ) {
      if ( value != value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == ">" ) {
      if ( value > value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == "<" ) {
      if ( value < value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == ">=" ) {
      if ( value >= value2 ) {
        mYesorno = true ;
      } // if
    } // else if
    else if ( oprator.name == "<=" ) {
      if ( value <= value2 ) {
        mYesorno = true ;
      } // if
    } // else if

  } // if
  


} // Parser::CAL_NOT_ID_StartArithExpOrBexp()

void Parser::CAL_NOT_ID_StartArithExp( float & value ) {
  StringProccess scanner ;
  Token sign ;
  float value2 ;
  CAL_NOT_ID_StartTerm( value ) ;
  // cout << value ;
  // mnexttoken = StringProccess::mnexttoken() ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
    sign = mnexttoken ;
    mnexttoken.name = "\0" ;
    CAL_Term( value2 ) ;
    // cout << value ;
    if ( sign.name == "+" )
      value = value + value2 ;
    else if ( sign.name == "-" )
      value = value - value2 ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
  } // while
} // Parser::CAL_NOT_ID_StartArithExp()

void Parser::CAL_NOT_ID_StartTerm( float & value ) {
  Token sign ;
  StringProccess scanner ;
  float value2 ;
  CAL_NOT_ID_StartFactor( value ) ;
  if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
    mindex++ ;
    mnexttoken = mtokenList[mindex] ;
  } // if
  
  // cout << mnexttoken.name ;
  while ( mnexttoken.name == "*" || mnexttoken.name == "/" ) {
    sign = mnexttoken ;
    mnexttoken.name = "\0" ;
    CAL_Factor( value2 ) ;
    if ( sign.name == "*" )
      value = value * value2 ;
    else if ( sign.name == "/" ) {
      if ( value2 == 0 )
        throw 0 ;
      value = value / value2 ;
    } // else if

    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
  }  // while
} // Parser::CAL_NOT_ID_StartTerm()

void Parser::CAL_NOT_ID_StartFactor( float & value ) {
  StringProccess scanner ;
  string sign ;
  // token = StringProccess::mnexttoken() ;
  if ( mnexttoken.type == SIGN ) {
    sign = mnexttoken.name ;
    mnexttoken.name = "\0" ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if

    if ( mnexttoken.type == NUM ) {
      Havedot( mnexttoken.name ) ;
      // cout << mnexttoken.name ;
      if ( sign == "+" )
        value = atof( mnexttoken.name.c_str() ) ;
      else if ( sign == "-" )
        value = -atof( mnexttoken.name.c_str() ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if
  } // if

  if ( mnexttoken.type == NUM ) {
    // cout << mnexttoken.name ;
    Havedot( mnexttoken.name ) ;
    value = atof( mnexttoken.name.c_str() ) ; 
    mnexttoken.name = "\0" ;
    return ;
  } // if

  if ( mnexttoken.name == "(" ) {
    // cout << "111" ;
    mnexttoken.name = "\0" ;
    CAL_ArithExp( value ) ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if

    if ( mnexttoken.name == ")" ) {
      mnexttoken.name = "\0" ;
      return ;
    } // if
  } // if
} // Parser::CAL_NOT_ID_StartFactor()

void Parser::CAL_Factor( float & value ) {               
  StringProccess scanner ;
  string sign ;
  if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
    mindex++ ;
    mnexttoken = mtokenList[mindex] ;
  } // if
  

  if ( mnexttoken.type == IDENT ) {
    value = IDvalue( mnexttoken.name ) ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if


    mnexttoken.name = "\0" ;
    return ;
  } // if
    
  if ( mnexttoken.type == SIGN ) {
    sign = mnexttoken.name ;
    mnexttoken.name = "\0" ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if
 
    // cout << "1111" ;

    if ( mnexttoken.type == NUM ) {
      Havedot( mnexttoken.name ) ;
      if ( sign == "+" )
        value = atof( mnexttoken.name.c_str() ) ;
      else if ( sign == "-" )
        value = -atof( mnexttoken.name.c_str() ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if

  } // if
  else if ( mnexttoken.type == NUM ) {
    // cout << mnexttoken.name ;
    // mvalue = mvalue + atoi( mnexttoken.name.c_str() ) ;
    // mindex++ ;
    // mnexttoken = mtokenList[mindex] ;
    // cout << mnexttoken.name ;
    // cout << "666666" ;
    /*
    if ( sign.name == "*" ) {
      // cout << "666" ;
      mvalue = mvalue * atoi( mnexttoken.name.c_str() ) ;
    } // if
    else if ( sign.name == "/" ) {
      mvalue = mvalue / atoi( mnexttoken.name.c_str() ) ;
    } // else if
    else if ( sign.name == "+" ) {
      mvalue = mvalue + atoi( mnexttoken.name.c_str() ) ;
    } // else if
    else if ( sign.name == "-" ) {
      mvalue = mvalue - atoi( mnexttoken.name.c_str() ) ;
    } // else if
    else {
      mvalue = atoi( mnexttoken.name.c_str() ) ;
    } // else
    */
    // cout << "111" ;
    // cout << mvalue << "\n" ;
    Havedot( mnexttoken.name ) ;
    value = atof( mnexttoken.name.c_str() ) ;
    mnexttoken.name = "\0" ;
    return ;
  } // else if
  else if ( mnexttoken.name == "(" ) {
    // cout << "1111" ;
    mnexttoken.name = "\0" ;
    CAL_ArithExp( value ) ;
    if ( mnexttoken.name == "\0" && mindex < mtokenList.size() - 1 ) {
      mindex++ ;
      mnexttoken = mtokenList[mindex] ;
    } // if

    if ( mnexttoken.name == ")" ) {
      mnexttoken.name = "\0" ;
      return ;
    } // if
  } // else if
} // Parser::CAL_Factor()

bool Parser::Defined( string name ) {
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( mVariableList[i].name == name )
      return true ;
  } // for

  return false ;
}  // Parser::Defined()




void Parser::Command( Token token ) {


  StringProccess scanner ;
  mnexttoken = token ;
  Token tempID ;
  // cout << mnexttoken.name ;
  if ( mnexttoken.name == "EOF" ) {
    return ;
  } // if
  
  if ( mnexttoken.name == "quit" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    // printf( "Program exits..." ) ;
    return ;
  } // if

  if ( mnexttoken.type == IDENT ) {
    tempID = mnexttoken ;
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == ":=" ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      // mnexttoken = StringProccess::mnexttoken() ;
      mnexttoken.name = "\0" ;
      ArithExp() ;
    } // if
    else {
      if ( mnexttoken.name == "+" || mnexttoken.name == "-" ||
           mnexttoken.name == "*" || mnexttoken.name == "/" || mnexttoken.name == ";"  ||
           mnexttoken.name == "=" || mnexttoken.name == "<>" || mnexttoken.name == ">" ||
           mnexttoken.name == "<" || mnexttoken.name == ">=" || mnexttoken.name == "<=" ) {
        if ( Defined( tempID.name ) )
          IDlessArithExpOrBexp() ;
        else {
          throw tempID ;
        } // else
      } // if
      else {
        throw mnexttoken.name ;
      } // else
    } // else

    // cout << mnexttoken.name ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == ";" ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      // cout << "great" ;
      return ;
    }  // if
    else {
      throw mnexttoken.name ;
    } // else
  } // if
  else {
    NOT_ID_StartArithExpOrBexp() ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == ";" ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      // cout << "great" ;
      return ;
    }  // if
    else {
      throw mnexttoken.name ;
    } // else
  } // else

} // Parser::Command()

void Parser::ArithExp() {
  StringProccess scanner ;
  Term() ;
  if ( mnexttoken.name == "\0" )
    mnexttoken = scanner.Peektoken() ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    Term() ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
  } // while()
} // Parser::ArithExp()

void Parser::IDlessArithExpOrBexp() {
  StringProccess scanner ;
  // mnexttoken = StringProccess::mnexttoken() ;
  string temp ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" || 
          mnexttoken.name == "*" || mnexttoken.name == "/" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    
    if ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
      mnexttoken.name = "\0" ;
      Term() ;
    } // if
    else if ( mnexttoken.name == "*" || mnexttoken.name == "/" ) {
      temp = mnexttoken.name ;
      mnexttoken.name = "\0" ;
      Factor( temp ) ;
    } // else if

    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
  } // while
  

  if ( BooleanOprator() )
    ArithExp() ;
  
} // Parser::IDlessArithExpOrBexp()


void Parser::Term() {
  StringProccess scanner ;
  string temp ;
  Factor( "" ) ;
  if ( mnexttoken.name == "\0" )
    mnexttoken = scanner.Peektoken() ;
  while ( mnexttoken.name == "*" || mnexttoken.name == "/" ) {
    temp = mnexttoken.name ;
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    Factor( temp ) ;
    mnexttoken = scanner.Peektoken() ;
  } // while
} // Parser::Term()

bool Parser::BooleanOprator() {
  StringProccess scanner ;
  if ( mnexttoken.name == "\0" ) 
    mnexttoken = scanner.Peektoken() ;
  if ( mnexttoken.name == "=" || mnexttoken.name == "<>" || mnexttoken.name == ">" || 
       mnexttoken.name == "<" || mnexttoken.name == ">=" || mnexttoken.name == "<=" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    return true ;
  } // if
  else { 
    if ( mnexttoken.name != ";" )
      throw mnexttoken.name ;
  } // else
  
  return false ;
} // Parser::BooleanOprator()

void Parser::NOT_ID_StartArithExpOrBexp() {
  NOT_ID_StartArithExp() ;
  if ( BooleanOprator() )
    ArithExp() ;


} // Parser::NOT_ID_StartArithExpOrBexp()

void Parser::NOT_ID_StartArithExp() {
  StringProccess scanner ;
  NOT_ID_StartTerm() ;
  // mnexttoken = StringProccess::mnexttoken() ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    Term() ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
  } // while
} // Parser::NOT_ID_StartArithExp()

void Parser::NOT_ID_StartTerm() {
  StringProccess scanner ;
  string temp ;
  NOT_ID_StartFactor() ;
  if ( mnexttoken.name == "\0" )
    mnexttoken = scanner.Peektoken() ;
  // cout << mnexttoken.name ;
  while ( mnexttoken.name == "*" || mnexttoken.name == "/" ) {
    temp = mnexttoken.name ;
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    Factor( temp ) ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
  }  // while
} // Parser::NOT_ID_StartTerm()

void Parser::NOT_ID_StartFactor() {
  StringProccess scanner ;
  // token = StringProccess::mnexttoken() ;
  if ( mnexttoken.type == SIGN ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == NUM ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if
    else {
      throw mnexttoken.name ;
    } // else
  } // if

  else if ( mnexttoken.type == NUM ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    return ;
  } // else if

  else if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    ArithExp() ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if
    else {
      throw mnexttoken.name ;
    } // else
  } // else if

  else {
    throw mnexttoken.name ;
  } // else
} // Parser::NOT_ID_StartFactor()

void Parser::Factor( string pretoken ) {
  StringProccess scanner ;
  if ( mnexttoken.name == "\0" ) 
    mnexttoken = scanner.Peektoken() ;
  // cout << mnexttoken.name ;
  if ( mnexttoken.type == IDENT ) {
    if ( Defined( mnexttoken.name ) ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // if
  
  else if ( mnexttoken.type == SIGN ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == NUM ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if
    else {
      throw mnexttoken.name ;
    } // else
  } // else if
  else if ( mnexttoken.type == NUM ) {
    // cout << mnexttoken.name ;
    if ( pretoken == "/" && mnexttoken.name == "0" )
      throw 0 ;
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    return ;
  } // else if
  else if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
    mnexttoken.name = "\0" ;
    ArithExp() ;
    if ( mnexttoken.name == "\0" )
      mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( scanner.Gettoken( mnexttoken ) ) ;
      mnexttoken.name = "\0" ;
      return ;
    } // if
    else {
      throw mnexttoken.name ;
    } // else
  } // else if
  else {
    throw mnexttoken.name ;
  } // else
} // Parser::Factor()

Token StringProccess::Gettoken( Token token ) {
  return token ;
} // StringProccess::Gettoken()

bool StringProccess::Case1( char a ) {
  if ( a >= 'a' && a <= 'z' )
    return true ;
  if ( a >= 'A' && a <= 'Z' )
    return true ;
  if ( a == '_' )
    return true ;
  return false ;
} // StringProccess::Case1()

bool StringProccess::Case2( char a ) {
  if ( a == '.' )
    return true ;

  if ( a >= '0' && a <= '9' )
    return true ;
  return false ;
} // StringProccess::Case2()

bool StringProccess::Case3( char b ) {
  if ( b == '_' ) 
    return false ;
  if ( b == '+' || b == '-' || b == '*' || b == '/' || b ==  '>' ||  
       b == '<' || b == '=' || b == '('  ||
       b == ')' || b == ':' || b ==  ';' )
    return true ;
  return false ;
} // StringProccess::Case3()

char StringProccess::GetNextChar() {
  int n = 0 ;
  char a ;
  if ( !scanf( "%c", &a ) )
    return '\0' ;
  if ( a == '\n' ) {
    gline++;
    gcol = 0 ;
  } // if
  else
  {
    gcol++;
  } // else
  
  return a ;
} // StringProccess::GetNextChar()

bool StringProccess::IsNum( char a ) {
  if ( a >= '0' && a <= '9' )
    return true ;
  if ( a == '_' )
    return true ;

  return false ;
} // StringProccess::IsNum()

char StringProccess::GetNextNonSpaceChar() {
  int k = 1 ;
  char b = '\0' ;
  char a = GetNextChar() ;
  if ( a == '\0' )
    return '\0' ;
  bool off = false ;
  while ( a == '\n' || a == ' ' || a == '\t' ) {
    a = GetNextChar() ;
  } // while()
  
  return a ;
} // StringProccess::GetNextNonSpaceChar()

string StringProccess::GetCaseOneToken( char a ) {
  string temp = "" ;
  int i = 0 ;
  char b = '\0' ;
  temp = temp + a ;
  b = cin.peek() ;
  while ( Case1( b ) || IsNum( b ) ) {
    a = GetNextChar() ;
    temp = temp + a ;
    b = cin.peek() ;
  } // while()
  
  return temp ;
} // StringProccess::GetCaseOneToken()

string StringProccess::GetCaseTwoToken( char a ) {
  string temp = "" ;
  int dot = 0 ;
  char b = '\0' ;
  if ( a == '"' ) { 
  } // if
  else if ( a >= '0' && a <= '9' ) {
    temp = temp + a ;
    b = cin.peek() ;
    if ( b == '.' ) {
      a = GetNextChar() ;
      temp = temp + a ;
      b = cin.peek() ;
      dot = 1 ;
    } // if

    while ( b >= '0' && b <= '9' ) {
      a = GetNextChar() ;
      temp = temp + a ;
      b = cin.peek() ;
      if ( b == '.' ) {
        if ( dot == 1 )
          return temp ;
        a = GetNextChar() ;
        temp = temp + a ;
        b = cin.peek() ;
        dot = 1 ;
      } // if
    } // while
    
    return temp ;
  } // else if
  else if ( a == '\'' ) {
  } // else if
  else if ( a == '.' ) {
    temp = temp + a ;
    b = cin.peek() ;
    while ( b >= '0' && b <= '9' ) {
      a = GetNextChar() ;
      temp = temp + a ;
      b = cin.peek() ;
    } // while
  } // else if
  
  return temp ;
} // StringProccess::GetCaseTwoToken()

string StringProccess::GetCaseThreeToken( char a ) {
  string temp = "" ;
  char b = '\0' ;
  if ( a == '<' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' || b == '>' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // if
  } // if
  
  else if ( a == '>' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // if
  } // if

  else if ( a == ':' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if
  else {
    temp = temp + a ;
  } // else
  
  return temp ;
} // StringProccess::GetCaseThreeToken()

Token StringProccess::Peektoken() {

  Token eof_token ;
  char tokenFirst = GetNextNonSpaceChar() ;
  if ( tokenFirst == '\0' ) {
    eof_token.name = "EOF" ;
    return eof_token ;
  } // if()
  
  Token token ;
  token.line = gline ;
  token.column = gcol ;
  bool isDivision = false ;
  char nextchar = '\0' ;
  char garbage ;
  while ( tokenFirst == '/' && !isDivision ) {
    if ( tokenFirst == '/' ) {
      nextchar = cin.peek() ;
      if ( nextchar == '/' ) {
        while ( garbage != '\n' ) scanf( "%c", &garbage ) ;
        tokenFirst = GetNextNonSpaceChar() ;

      } // if
      else {
        isDivision = true ;
      } // else
    } // if
    
    garbage = '\0' ;
  } // while

  if ( Case1( tokenFirst ) ) {
    token.name = GetCaseOneToken( tokenFirst ) ;
    token.type = IDENT ;
  } // if
  else if ( Case2( tokenFirst ) ) {
    token.name = GetCaseTwoToken( tokenFirst ) ;
    token.type = NUM ;
  } // else if
  else if ( Case3( tokenFirst ) ) {
    token.name = GetCaseThreeToken( tokenFirst ) ;
    token.type = SS ;
  } // else if
  else {
    // while ( garbage != '\n' ) scanf( "%c", &garbage ) ;

    throw tokenFirst ;
    // throw error ;
  } // else


  if ( token.name == ":" )
    throw token.name[0] ;
  if ( token.name == "+" || token.name == "-" )
    token.type = SIGN ;
  return token ;


} // StringProccess::Peektoken()


