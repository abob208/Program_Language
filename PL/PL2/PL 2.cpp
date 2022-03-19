# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <iostream>
# include <vector>
# include <string>
using namespace std;
enum TokenType { IDENT = 34512, SIGN = 87232, CONSTANT = 29742, QUIT = 88888, SS = 456465 } ;
enum VariableType { INT, CHAR, FLOAT, STRING, BOOL, VOID, NO };
struct Token {
  string name ;
  int column ;
  int line ;
  TokenType type ;
};

struct Variable {
  VariableType type ;
  string name ;
  float value ;
  int arraysize ;
  bool isfloat ;
  bool isarray ;
};

struct Function {
  string name ;
  vector<Token> list ;
  vector<Variable> parameters ;
};

class Parser {
  public :
  void User_input() ;
  void Definition() ;
  void Type_specifier() ;
  void Function_definition_or_declarators() ;
  void Rest_of_declarators() ;
  void Function_definition_without_ID() ;
  void Formal_parameter_list() ;
  void Compound_statement() ;
  void Declaration() ;
  void Statement() ;
  void Expression() ;
  void Basic_expression() ;
  void Rest_of_Identifier_started_basic_exp() ;
  void Rest_of_PPMM_Identifier_started_basic_exp() ;
  void Sign() ;
  void Actual_parameter_list() ;
  void Assignment_operator() ;
  void Romce_and_romloe() ;
  void Rest_of_maybe_logical_OR_exp() ;
  void Maybe_logical_AND_exp() ;
  void Rest_of_maybe_logical_AND_exp() ;
  void Maybe_bit_OR_exp() ;
  void Rest_of_maybe_bit_OR_exp() ;
  void Maybe_bit_ex_OR_exp() ;
  void Rest_of_maybe_bit_ex_OR_exp() ;
  void Maybe_bit_AND_exp() ;
  void Rest_of_maybe_bit_AND_exp() ;
  void Maybe_equality_exp() ;
  void Rest_of_maybe_equality_exp() ;
  void Maybe_relational_exp() ;
  void Rest_of_maybe_relational_exp() ;
  void Maybe_shift_exp() ;
  void Rest_of_maybe_shift_exp() ;
  void Maybe_additive_exp() ;
  void Rest_of_maybe_additive_exp() ;
  void Maybe_mult_exp() ;
  void Rest_of_maybe_mult_exp() ;
  void Unary_exp() ;
  void Signed_unary_exp() ;
  void Unsigned_unary_exp() ;
  void Print() ;
  float IDvalue( string ID ) ;
  void Havedot( string num ) ;
  void Clear() ;
  bool IsDone( vector<Token> list ) ;
  bool IsDefined( string name ) ;
  bool Global_IsDefined( string name ) ;
  void SetInitFunction() ;
  void Execute() ;
  void ListAllVariables() ;
  void ListAllFunctions() ;
  void ListVariable( string key ) ;
  void ListFunction( string key ) ;
  VariableType Whattype( string key ) ;
  private :
  vector<Token> mtokenList ;
  vector<Variable> mVariableList ; // 宣告成功的變數 
  vector<Function> mFunctionList ; // 宣告成功的函式 
  vector<Variable> mtempVariableList ; // 紀錄宣告多個變數 或 是區域變數 
  vector<Variable> mtempFunctionParameter ; // 現在這個函式的參數 
  bool mOprator ;
  bool mYesorno ;
  bool mChange ;
  bool misfloat ;
  Token mnexttoken ;
  float mvalue ;
  int mindex ;
  bool misdefined ;
};
class Scanner {
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
int gtempline = 0 ;
int main() {
  int uTestNum = 0 ;
  char ch = '\0' ;
  scanf( "%d%c", &uTestNum, &ch ) ;
  Parser parser ;
  char garbage = '\0' ;
  Scanner scanner ;
  Token token ;
  bool docalculation = true ;
  bool quit = false ;
  cout << "Our-C running ...\n" ;

  parser.User_input() ;


  cout << "> Our-C exited ..." ;
} // main()

VariableType Parser::Whattype( string key ) {
  if ( key == "char" )
    return CHAR ;
  if ( key == "int" )
    return INT ;
  if ( key == "string" )
    return STRING ;
  if ( key == "float" )
    return FLOAT ;
  if ( key == "bool" )
    return BOOL ;
  if ( key == "void" )
    return VOID ;
    
  return NO ;
} // Parser::Whattype()


void Parser::Execute() {
  if ( mtokenList[0].name == "Done" && mtokenList[1].name == "("
       && mtokenList[2].name == ")" && mtokenList[3].name == ";" ) {
    return ;
  } // if

  cout << "> " ;
  if ( mtokenList[0].name == "ListAllVariables" && mtokenList[1].name == "("
       && mtokenList[2].name == ")" && mtokenList[3].name == ";" ) {

    ListAllVariables() ;
  } // if

  if ( mtokenList[0].name == "ListAllFunctions" && mtokenList[1].name == "("
       && mtokenList[2].name == ")" && mtokenList[3].name == ";" ) {

    ListAllFunctions() ;
  } // if

  if ( mtokenList[0].name == "ListVariable" && mtokenList[1].name == "("
       && mtokenList[3].name == ")" && mtokenList[4].name == ";" ) {

    ListVariable( mtokenList[2].name ) ;
  } // if

  if ( mtokenList[0].name == "ListFunction" && mtokenList[1].name == "("
       && mtokenList[3].name == ")" && mtokenList[4].name == ";" ) {

    ListFunction( mtokenList[2].name ) ;
  } // if

  cout << "Statement executed ...\n" ;
} // Parser::Execute()

void Parser::ListAllVariables() {
  Variable temp ;
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    for ( int j = i ; j < mVariableList.size() ; j++ ) {
      if ( mVariableList[j].name < mVariableList[i].name ) {
        temp = mVariableList[j] ;
        mVariableList[j] = mVariableList[i] ;
        mVariableList[i] = temp ;
      } // if
    } // for

  } // for

  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( mVariableList[i].name != "cout" && mVariableList[i].name != "cin" )
      cout << mVariableList[i].name << "\n" ;
  } // for
} // Parser::ListAllVariables()

void Parser::ListAllFunctions() {
  Function temp ;
  for ( int i = 0 ; i < mFunctionList.size() ; i++ ) {
    for ( int j = i ; j < mFunctionList.size() ; j++ ) {
      if ( mFunctionList[j].name < mFunctionList[i].name ) {
        temp = mFunctionList[j] ;
        mFunctionList[j] = mFunctionList[i] ;
        mFunctionList[i] = temp ;
      } // if
    } // for

  } // for

  for ( int i = 0 ; i < mFunctionList.size() ; i++ ) {
    if ( mFunctionList[i].name != "Done" && mFunctionList[i].name != "ListAllVariables" && 
         mFunctionList[i].name != "ListAllFunctions" && mFunctionList[i].name != "ListVariable" && 
         mFunctionList[i].name != "ListFunction" ) 
      cout << mFunctionList[i].name << "()\n" ;
  } // for
} // Parser::ListAllFunctions()

void Parser::ListVariable( string key ) {
  key.erase( 0, 1 ) ;
  key.erase( key.size() - 1, 1 ) ;
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( key == mVariableList[i].name ) {
      if ( mVariableList[i].type == CHAR )
        cout << "char " ;
      if ( mVariableList[i].type == INT )
        cout << "int " ;
      if ( mVariableList[i].type == FLOAT )
        cout << "float " ;
      if ( mVariableList[i].type == STRING )
        cout << "string " ;
      if ( mVariableList[i].type == BOOL )
        cout << "bool " ;
      
      cout << mVariableList[i].name ;
      if ( mVariableList[i].isarray )
        cout << "[ " << mVariableList[i].arraysize << " ]" ;
      cout << " ;\n" ;
    } // if
  } // for
} // Parser::ListVariable()

void Parser::ListFunction( string key ) {
  // 隱藏有呼叫這個 
  key.erase( 0, 1 ) ;
  key.erase( key.size() - 1, 1 ) ; 
  Function function ;
  function.list.clear() ;
  function.name = "" ;
  function.parameters.clear() ;
  int space = 0 ;

  for ( int i = 0 ; i < mFunctionList.size() ; i++ ) {
    if ( mFunctionList[i].name == key )
      function = mFunctionList[i] ;
  } // for
  
  for ( int i = 0 ; i < function.list.size() ; i++ ) {

    cout << function.list[i].name ;
    if ( i + 1 < function.list.size() && function.list[ i + 1 ].name == "}" )
      space = space - 2 ;
    if ( function.list[i].name == "{" )
      space = space + 2 ;

    if ( function.list[i].name == "if" || function.list[i].name == "while" )
      cout << " " ;
    else if ( i + 1 < function.list.size() && function.list[ i ].name == "(" &&
              function.list[ i + 1 ].name == ")" )
      ;
    else if ( i + 1 < function.list.size() && function.list[ i ].name == "(" &&
              function.list[ i + 1 ].name == "(" )
      cout << " " ;
    else if ( i + 1 < function.list.size() && function.list[ i + 1 ].name != "["
              && function.list[ i + 1 ].name != "(" && function.list[i].name != ";" 
              && function.list[i].name != "{" && function.list[i].name != "}"  
              && function.list[ i + 1 ].name != "," 
              && function.list[ i + 1 ].name != "++" && function.list[ i + 1 ].name != "--" )
      cout << " " ;


    if ( function.list[i].name == ";" || function.list[i].name == "{" 
         || function.list[i].name == "}" ) {
      cout << "\n" ;
      for ( int j = 0 ; j < space ; j++ ) {
        cout << " " ;
      } // for
    } // if

  } // for
  
  // cout << "\n" ;
} // Parser::ListFunction()

void Parser::SetInitFunction() {
  Function function ;
  function.name = "Done" ;
  mFunctionList.push_back( function ) ;
  function.name = "ListAllVariables" ;
  mFunctionList.push_back( function ) ;
  function.name = "ListAllFunctions" ;
  mFunctionList.push_back( function ) ;
  function.name = "ListVariable" ;
  mFunctionList.push_back( function ) ;
  function.name = "ListFunction" ;
  mFunctionList.push_back( function ) ;
  
  Variable variable ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  variable.name = "cout" ;
  mVariableList.push_back( variable ) ;
  variable.name = "cin" ;
  mVariableList.push_back( variable ) ;
} // Parser::SetInitFunction()

bool Parser::IsDefined( string name ) {
  
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( mVariableList[i].name == name ) {
      return true ;
    } // if
  } // for
  
  for ( int i = 0 ; i < mFunctionList.size() ; i++ ) {
    if ( mFunctionList[i].name == name ) {
      return true ;
    } // if
  } // for

  for ( int i = 0 ; i < mtempVariableList.size() ; i++ ) {
    if ( mtempVariableList[i].name == name ) {
      return true ;
    } // if
  } // for

  for ( int i = 0 ; i < mtempFunctionParameter.size() ; i++ ) {
    if ( mtempFunctionParameter[i].name == name ) {
      return true ;
    } // if
  } // for

  return false ;
} // Parser::IsDefined()

bool Parser::Global_IsDefined( string name ) {
  
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( mVariableList[i].name == name ) {
      mVariableList[i].type = Whattype( mtokenList[0].name ) ;
      return true ;
    } // if
  } // for
  
  for ( int i = 0 ; i < mFunctionList.size() ; i++ ) {
    if ( mFunctionList[i].name == name ) {
      mFunctionList[i].list = mtokenList ;
      return true ;
    } // if
  } // for


  return false ;
} // Parser::Global_IsDefined()


bool Parser::IsDone( vector<Token> list ) {
  if ( list.empty() )
    return false ;
  if ( list[0].name == "Done" && list[1].name == "(" && list[2].name == ")" && list[3].name == ";" ) 
    return true ;
  return false ;
} // Parser::IsDone()

void Parser::User_input() {
  char a = '\0' ;
  Variable variable ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  SetInitFunction() ;
  misdefined = false ;
  Scanner scanner ;
  char garbage = '\0' ;
  bool noHaveFirstToken = true ;
  while ( noHaveFirstToken ) {
    try {
      mnexttoken = scanner.Peektoken() ;
      noHaveFirstToken = false ;
    } // try
    catch ( char a ) {
      cout << "> " << "Line " << 1 << " : unrecognized token with first char : '" << a << "'\n" ;
      while ( garbage != '\n' ) garbage = scanner.GetNextChar() ;
      noHaveFirstToken = true ;
      garbage = '\0' ;
    } // catch
  } // while

  while ( mnexttoken.name != "EOF" && !IsDone( mtokenList ) ) {

    Clear() ;
    try {
      if ( mnexttoken.name == "void" ) {

        Definition() ;
      } // if
      else if ( mnexttoken.name == "int" || mnexttoken.name == "char" || 
                mnexttoken.name == "float" || mnexttoken.name == "string" || mnexttoken.name == "bool" ) {

        Definition() ;
      } // else if
      else {

        Statement() ;

        Execute() ;
      } // else

      if ( gtempline == -1 )
        gtempline = 0 ;
      gline = 1 + gtempline ; // 已經讀進下一段的token了 要改 
    } // try
    catch ( char a ) {
      cout << "> " << "Line " << gline << " : unrecognized token with first char : '" << a << "'\n" ;
      while ( garbage != '\n' ) garbage = scanner.GetNextChar() ;
      gline = 1 ;
      mnexttoken = scanner.Peektoken() ;
    } // catch
    catch ( Token token ) {
      cout << "> " << "Line " << gline << " : unexpected token : '" << token.name << "'\n" ;
      while ( garbage != '\n' ) garbage = scanner.GetNextChar() ;
      gline = 1 ;
      mnexttoken = scanner.Peektoken() ;
    } // catch
    catch ( string name ) {
      cout << "> " << "Line " << gline << " : undefined identifier : '" << name << "'\n" ;
      while ( garbage != '\n' ) garbage = scanner.GetNextChar() ;
      gline = 1 ;
      mnexttoken = scanner.Peektoken() ;
    } // catch
    catch ( int over ) {
      mnexttoken.name = "EOF" ;
    } // catch

    garbage = '\0' ;
  } // while
} // Parser::User_input()

void Parser::Definition() {
  Scanner scanner ;
  if ( mnexttoken.name == "void" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == IDENT ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Function_definition_without_ID() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // if
  else {
    Type_specifier() ;
    if ( mnexttoken.type == IDENT ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Function_definition_or_declarators() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else
} // Parser::Definition()

void Parser::Type_specifier() {
  Scanner scanner ;
  if ( mnexttoken.name == "int" || mnexttoken.name == "char" || mnexttoken.name == "float" || 
       mnexttoken.name == "string" || mnexttoken.name == "bool" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Type_specifier()

void Parser::Function_definition_or_declarators() {
  Function function ;
  Variable variable ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  if ( mnexttoken.name == "(" ) {
    Function_definition_without_ID() ;
 

  } // if
  else {
    Rest_of_declarators() ;
    if ( !Global_IsDefined( mtokenList[1].name ) ) {
      cout << "> Definition of " << mtokenList[1].name << " entered ...\n" ;
      variable.name = mtokenList[1].name ;
      variable.type = Whattype( mtokenList[0].name ) ;
      if ( mtokenList[2].name == "[" ) {
        variable.isarray = true ;
        variable.arraysize = atoi( mtokenList[3].name.c_str() ) ;
      } // if

      mVariableList.push_back( variable ) ;
      variable.isarray = false ;
      variable.arraysize = 0 ;
    } // if
    else {
      cout << "> New definition of " << mtokenList[1].name << " entered ...\n" ;
    } // else

    for ( int i = 0 ; i < mtempVariableList.size() ; i++ ) {
      if ( !Global_IsDefined( mtempVariableList[i].name ) ) {
        cout << "Definition of " << mtempVariableList[i].name << " entered ...\n" ;
        mtempVariableList[i].type = Whattype( mtokenList[0].name ) ;
        mVariableList.push_back( mtempVariableList[i] ) ;
      } // if
      else
        cout << "New definition of " << mtempVariableList[i].name << " entered ...\n" ;
    } // for
  }  // else
} // Parser::Function_definition_or_declarators()

void Parser::Rest_of_declarators() {
  Variable variable ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  Scanner scanner ;
  if ( mnexttoken.name == "[" ) {
    
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == CONSTANT ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.name == "]" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
      } // if
      else {
        throw mnexttoken ;
      } // else
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // if

  while ( mnexttoken.name == "," ) {
    variable.isarray = false ;
    variable.arraysize = 0 ;
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == IDENT ) {
      variable.name = mnexttoken.name ;
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else

    if ( mnexttoken.name == "[" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.type == CONSTANT ) {
        variable.isarray = true ;
        variable.arraysize = atoi( mnexttoken.name.c_str() ) ;
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
        if ( mnexttoken.name == "]" ) {
          mtokenList.push_back( mnexttoken ) ;
          mnexttoken = scanner.Peektoken() ;
        } // if
        else {
          throw mnexttoken ;
        } // else
      } // if
      else {
        throw mnexttoken ;
      } // else
    } // if

    mtempVariableList.push_back( variable ) ;
  } // while
  
  if ( mnexttoken.name == ";" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Rest_of_declarators()

void Parser::Function_definition_without_ID() {
  Function function ;
  Scanner scanner ;
  if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == "void" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else if ( mnexttoken.name == "int" || mnexttoken.name == "char" || mnexttoken.name == "float" || 
              mnexttoken.name == "string" || mnexttoken.name == "bool" ) {
      Formal_parameter_list() ;
    } // else if

    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else

    Compound_statement() ;
    if ( !Global_IsDefined( mtokenList[1].name ) ) {
      cout << "> Definition of " << mtokenList[1].name << "() entered ...\n" ;
      function.list = mtokenList ;
      function.name = mtokenList[1].name ;
      mFunctionList.push_back( function ) ;
    } // if
    else {
      
      cout << "> New definition of " << mtokenList[1].name << "() entered ...\n" ;
    } // else
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Function_definition_without_ID()

void Parser::Formal_parameter_list() {
  Scanner scanner ;
  Variable variable ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  Type_specifier() ;
  if ( mnexttoken.name == "&" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // if
  
  if ( mnexttoken.type == IDENT ) {
    variable.name = mnexttoken.name ;
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == "[" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.type == CONSTANT ) {
        variable.isarray = true ;
        variable.arraysize = atoi( mnexttoken.name.c_str() ) ;
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
        if ( mnexttoken.name == "]" ) {
          mtokenList.push_back( mnexttoken ) ;
          mnexttoken = scanner.Peektoken() ;
        } // if
        else {
          throw mnexttoken ;
        } // else
      } // if
      else {
        throw mnexttoken ;
      } // else
    } // if
  } // if
  else {
    throw mnexttoken ;
  } // else
  
  mtempFunctionParameter.push_back( variable ) ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  while ( mnexttoken.name == "," ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Type_specifier() ;
    if ( mnexttoken.name == "&" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if

    if ( mnexttoken.type == IDENT ) {
      variable.name = mnexttoken.name ;
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.name == "[" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
        if ( mnexttoken.type == CONSTANT ) {
          variable.isarray = true ;
          variable.arraysize = atoi( mnexttoken.name.c_str() ) ;
          mtokenList.push_back( mnexttoken ) ;
          mnexttoken = scanner.Peektoken() ;
          if ( mnexttoken.name == "]" ) {
            mtokenList.push_back( mnexttoken ) ;
            mnexttoken = scanner.Peektoken() ;
          } // if
          else {
            throw mnexttoken ;
          } // else
        } // if
        else {
          throw mnexttoken ;
        } // else
      } // if
    } // if
    else {
      throw mnexttoken ;
    } // else
    
    mtempFunctionParameter.push_back( variable ) ;
    variable.isarray = false ;
    variable.arraysize = 0 ;
  } // while
} // Parser::Formal_parameter_list()

void Parser::Compound_statement() {
  Scanner scanner ;
  if ( mnexttoken.name == "{" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;

    while ( mnexttoken.name != "}" ) {
      if ( mnexttoken.name == "int" || mnexttoken.name == "char" || 
           mnexttoken.name == "float" || mnexttoken.name == "string" || mnexttoken.name == "bool" ) {
        Declaration() ;
      } // if
      else {
        Statement() ;
      } // else

    } // while  有可能卡無窮 我不知道這樣寫可不可以
    
    if ( mnexttoken.name == "}" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Compound_statement()

void Parser::Declaration() {
  Scanner scanner ;
  Variable variable ;
  variable.isarray = false ;
  variable.arraysize = 0 ;
  Type_specifier() ;
  if ( mnexttoken.type == IDENT ) {
    variable.name = mnexttoken.name ;
    mtempVariableList.push_back( variable ) ;
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Rest_of_declarators() ;
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Declaration()

void Parser::Statement() {
  Scanner scanner ;
  if ( mnexttoken.name == ";" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // if
  else if ( mnexttoken.name == "return" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == IDENT || mnexttoken.name == "++" || mnexttoken.name == "--" 
         || mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" 
         || mnexttoken.type == CONSTANT || mnexttoken.name == "(" )
      Expression() ; // 我不太確定條件要放啥 可能有問題
    if ( mnexttoken.name == ";" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else if ( mnexttoken.name == "if" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == "(" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Expression() ;
      if ( mnexttoken.name == ")" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
      } // if
      else {
        throw mnexttoken ;
      } // else
    
      Statement() ;
      if ( mnexttoken.name == "else" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
        Statement() ;
      } // if
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else if ( mnexttoken.name == "while" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == "(" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Expression() ;
      if ( mnexttoken.name == ")" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
      } // if
      else {
        throw mnexttoken ;
      } // else
      
      Statement() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else if ( mnexttoken.name == "do" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Statement() ;
    if ( mnexttoken.name == "while" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.name == "(" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
        Expression() ;
        if ( mnexttoken.name == ")" ) {
          mtokenList.push_back( mnexttoken ) ;
          mnexttoken = scanner.Peektoken() ;
          if ( mnexttoken.name == ";" ) {
            mtokenList.push_back( mnexttoken ) ;
            mnexttoken = scanner.Peektoken() ;
          } // if
          else {
            throw mnexttoken ;
          } // else
        } // if
        else {
          throw mnexttoken ;
        } // else
      } // if
      else {
        throw mnexttoken ;
      } // else
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else if ( mnexttoken.name == "{" ) {
    Compound_statement() ;
  } // else if
  else {
    Expression() ;
    if ( mnexttoken.name == ";" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else
  
} // Parser::Statement()

void Parser::Expression() {
  Scanner scanner ;
  Basic_expression() ;
  while ( mnexttoken.name == "," ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Basic_expression() ;
  } // while
} // Parser::Expression()

void Parser::Basic_expression() {
  Scanner scanner ;
  if ( mnexttoken.type == IDENT ) {
    if ( !IsDefined( mnexttoken.name ) ) 
      throw mnexttoken.name ;
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Rest_of_Identifier_started_basic_exp() ;
  } // if
  else if ( mnexttoken.name == "++" || mnexttoken.name == "--" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == IDENT ) {
      if ( !IsDefined( mnexttoken.name ) ) 
        throw mnexttoken.name ;
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Rest_of_PPMM_Identifier_started_basic_exp() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else if ( mnexttoken.name == "+" || mnexttoken.name == "-"  || mnexttoken.name == "!" ) {
    Sign() ;
    while ( mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" ) {
      Sign() ;
    } // while
    
    Signed_unary_exp() ;
    Romce_and_romloe() ;

  } // else if
  else if ( mnexttoken.type == CONSTANT ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Romce_and_romloe() ;
  } // else if
  else if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Expression() ;
    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else

    Romce_and_romloe() ;
  } // else if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Basic_expression()

void Parser::Rest_of_Identifier_started_basic_exp() {
  Scanner scanner ;
  if ( mnexttoken.name == "[" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Expression() ;
    if ( mnexttoken.name == "]" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
    
    if ( mnexttoken.name == "++" || mnexttoken.name == "--" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Romce_and_romloe() ;
    } // if
    else if ( mnexttoken.name == "+=" || mnexttoken.name == "-=" || mnexttoken.name == "*=" ||
              mnexttoken.name == "/=" || mnexttoken.name == "%=" || mnexttoken.name == "=" ) {
      Assignment_operator() ;
      Basic_expression() ;
    } // else if
    else {
      Romce_and_romloe() ;
    } // else
  } // if

  else if ( mnexttoken.name == "++" || mnexttoken.name == "--" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Romce_and_romloe() ;
  } // else if
    
  else if ( mnexttoken.name == "+=" || mnexttoken.name == "-=" || mnexttoken.name == "*=" || 
            mnexttoken.name == "/=" || mnexttoken.name == "%=" || mnexttoken.name == "=" ) {
    Assignment_operator() ;
    Basic_expression() ;
  } // else if

  else if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == IDENT || mnexttoken.name == "++" || mnexttoken.name == "--" || 
         mnexttoken.name == "+" || mnexttoken.name == "!" ||
         mnexttoken.name == "-" || mnexttoken.type == CONSTANT || mnexttoken.name == "(" ) {
      Actual_parameter_list() ;
    } // if
    
    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
    
    Romce_and_romloe() ;
  } // else if
  else {
    Romce_and_romloe() ;
  } // else
} // Parser::Rest_of_Identifier_started_basic_exp()

void Parser::Rest_of_PPMM_Identifier_started_basic_exp() {
  Scanner scanner ;
  if ( mnexttoken.name == "[" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Expression() ;
    if ( mnexttoken.name == "]" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // if
  
  Romce_and_romloe() ;
} // Parser::Rest_of_PPMM_Identifier_started_basic_exp()

void Parser::Sign() {
  Scanner scanner ;
  if ( mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Sign()

void Parser::Actual_parameter_list() {
  Scanner scanner ;
  Basic_expression() ;
  while ( mnexttoken.name == "," ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Basic_expression() ;
  } // while
} // Parser::Actual_parameter_list()

void Parser::Assignment_operator() {
  Scanner scanner ;
  if ( mnexttoken.name == "+=" || mnexttoken.name == "-=" || mnexttoken.name == "*=" || 
       mnexttoken.name == "/=" || mnexttoken.name == "%=" || mnexttoken.name == "=" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Assignment_operator()

void Parser::Romce_and_romloe() {
  Scanner scanner ;
  Rest_of_maybe_logical_OR_exp() ;
  if ( mnexttoken.name == "?" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Basic_expression() ;
    if ( mnexttoken.name == ":" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Basic_expression() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // if
} // Parser::Romce_and_romloe()

void Parser::Rest_of_maybe_logical_OR_exp() {
  Scanner scanner ;
  Rest_of_maybe_logical_AND_exp() ;
  while ( mnexttoken.name == "||" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_logical_AND_exp() ;
  } // while
} // Parser::Rest_of_maybe_logical_OR_exp()

void Parser::Maybe_logical_AND_exp() {
  Scanner scanner ;
  Maybe_bit_OR_exp() ;
  while ( mnexttoken.name == "&&" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_bit_OR_exp() ;
  } // while

} // Parser::Maybe_logical_AND_exp()

void Parser::Rest_of_maybe_logical_AND_exp() {
  Scanner scanner ;
  Rest_of_maybe_bit_OR_exp() ;
  while ( mnexttoken.name == "&&" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_bit_OR_exp() ;
  } // while
} // Parser::Rest_of_maybe_logical_AND_exp()

void Parser::Maybe_bit_OR_exp() {
  Scanner scanner ;
  Maybe_bit_ex_OR_exp() ;
  while ( mnexttoken.name == "|" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_bit_ex_OR_exp() ;
  } // while
} // Parser::Maybe_bit_OR_exp()

void Parser::Rest_of_maybe_bit_OR_exp() {
  Scanner scanner ;
  Rest_of_maybe_bit_ex_OR_exp() ;
  while ( mnexttoken.name == "|" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_bit_ex_OR_exp() ;
  } // while
} // Parser::Rest_of_maybe_bit_OR_exp()

void Parser::Maybe_bit_ex_OR_exp() {
  Scanner scanner ;
  Maybe_bit_AND_exp() ;
  while ( mnexttoken.name == "^" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_bit_AND_exp() ;
  } // while
} // Parser::Maybe_bit_ex_OR_exp()

void Parser::Rest_of_maybe_bit_ex_OR_exp() {
  Scanner scanner ;
  Rest_of_maybe_bit_AND_exp() ;
  while ( mnexttoken.name == "^" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_bit_AND_exp() ;
  } // while	
} // Parser::Rest_of_maybe_bit_ex_OR_exp()

void Parser::Maybe_bit_AND_exp() {
  Scanner scanner ;
  Maybe_equality_exp() ;
  while ( mnexttoken.name == "&" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_equality_exp() ;
  } // while
} // Parser::Maybe_bit_AND_exp()

void Parser::Rest_of_maybe_bit_AND_exp() {
  Scanner scanner ;
  Rest_of_maybe_equality_exp() ;
  while ( mnexttoken.name == "&" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_equality_exp() ;
  } // while
} // Parser::Rest_of_maybe_bit_AND_exp()

void Parser::Maybe_equality_exp() {
  Scanner scanner ;
  Maybe_relational_exp() ;
  while ( mnexttoken.name == "==" || mnexttoken.name == "!=" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_relational_exp() ;
  } // while
} // Parser::Maybe_equality_exp()

void Parser::Rest_of_maybe_equality_exp() {
  Scanner scanner ;
  Rest_of_maybe_relational_exp() ;
  while ( mnexttoken.name == "==" || mnexttoken.name == "!=" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_relational_exp() ;
  } // while
} // Parser::Rest_of_maybe_equality_exp()

void Parser::Maybe_relational_exp() {
  Scanner scanner ;
  Maybe_shift_exp() ;
  while ( mnexttoken.name == ">" || mnexttoken.name == "<" || 
          mnexttoken.name == ">=" || mnexttoken.name == "<=" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_shift_exp() ;
  } // while
} // Parser::Maybe_relational_exp()

void Parser::Rest_of_maybe_relational_exp() {
  Scanner scanner ;
  Rest_of_maybe_shift_exp() ;
  while ( mnexttoken.name == ">" || mnexttoken.name == "<" || 
          mnexttoken.name == ">=" || mnexttoken.name == "<=" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_shift_exp() ;
  } // while
} // Parser::Rest_of_maybe_relational_exp()

void Parser::Maybe_shift_exp() {
  Scanner scanner ;
  Maybe_additive_exp() ;
  while ( mnexttoken.name == "<<" || mnexttoken.name == ">>" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_additive_exp() ;
  } // while
} // Parser::Maybe_shift_exp()

void Parser::Rest_of_maybe_shift_exp() {
  Scanner scanner ;
  Rest_of_maybe_additive_exp() ;
  while ( mnexttoken.name == "<<" || mnexttoken.name == ">>" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_additive_exp() ;
  } // while
} // Parser::Rest_of_maybe_shift_exp() 

void Parser::Maybe_additive_exp() {
  Scanner scanner ;
  Maybe_mult_exp() ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_mult_exp() ;
  } // while
} // Parser::Maybe_additive_exp()

void Parser::Rest_of_maybe_additive_exp() {
  Scanner scanner ;
  Rest_of_maybe_mult_exp() ;
  while ( mnexttoken.name == "+" || mnexttoken.name == "-" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Maybe_mult_exp() ;
  } // while
} // Parser::Rest_of_maybe_additive_exp()

void Parser::Maybe_mult_exp() {
  Scanner scanner ;
  Unary_exp() ;
  Rest_of_maybe_mult_exp() ;
} // Parser::Maybe_mult_exp()

void Parser::Rest_of_maybe_mult_exp() {
  Scanner scanner ;
  while ( mnexttoken.name == "*" || mnexttoken.name == "/" || mnexttoken.name == "%" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Unary_exp() ;
  } // while
} // Parser::Rest_of_maybe_mult_exp()

void Parser::Unary_exp() {
  Scanner scanner ;
  if ( mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" ) {
    Sign() ;
    while ( mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" ) {
      Sign() ;
    } // while

    Signed_unary_exp() ;
  } // if
  else if ( mnexttoken.type == IDENT || mnexttoken.type == CONSTANT || mnexttoken.name == "(" ) {
    Unsigned_unary_exp() ;
  } // else if
  else if ( mnexttoken.name == "++" || mnexttoken.name == "--" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.type == IDENT ) {
      if ( !IsDefined( mnexttoken.name ) ) 
        throw mnexttoken.name ;
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.name == "[" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
        Expression() ;
        if ( mnexttoken.name == "]" ) {
          mtokenList.push_back( mnexttoken ) ;
          mnexttoken = scanner.Peektoken() ;

        } // if
        else {
          throw mnexttoken ;
        } // else
      } // if
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else {
    throw mnexttoken ;
  } // else
} // Parser::Unary_exp()

void Parser::Signed_unary_exp() {
  Scanner scanner ;
  if ( mnexttoken.type == IDENT ) {
    if ( !IsDefined( mnexttoken.name ) ) 
      throw mnexttoken.name ;
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == "(" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.type == IDENT || mnexttoken.name == "++" || mnexttoken.name == "--" || 
           mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" ||
           mnexttoken.type == CONSTANT || mnexttoken.name == "(" ) {
        Actual_parameter_list() ;
      } // if
      
      if ( mnexttoken.name == ")" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
      } // if
      else {
        throw mnexttoken ;
      } // else
    } // if
    else if ( mnexttoken.name == "[" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Expression() ;
      if ( mnexttoken.name == "]" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;

      } // if
      else {
        throw mnexttoken ;
      } // else
    } // else if
  } // if
  else if ( mnexttoken.type == CONSTANT ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // else if
  else if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Expression() ;
    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else {
    throw mnexttoken ;
  } // else
  
} // Parser::Signed_unary_exp()

void Parser::Unsigned_unary_exp() {
  Scanner scanner ;
  if ( mnexttoken.type == IDENT ) {
    if ( !IsDefined( mnexttoken.name ) ) 
      throw mnexttoken.name ;
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    if ( mnexttoken.name == "(" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      if ( mnexttoken.type == IDENT || mnexttoken.name == "++" || mnexttoken.name == "--" || 
           mnexttoken.name == "+" || mnexttoken.name == "-" || mnexttoken.name == "!" ||
           mnexttoken.type == CONSTANT || mnexttoken.name == "(" ) {
        Actual_parameter_list() ;
      } // if
      
      if ( mnexttoken.name == ")" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
      } // if
      else {
        throw mnexttoken ;
      } // else
    } // if
    else if ( mnexttoken.name == "[" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
      Expression() ;
      if ( mnexttoken.name == "]" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;

      } // if
      else {
        throw mnexttoken ;
      } // else
      
      if ( mnexttoken.name == "++" || mnexttoken.name == "--" ) {
        mtokenList.push_back( mnexttoken ) ;
        mnexttoken = scanner.Peektoken() ;
      } // if
    } // else if
    else if ( mnexttoken.name == "++" || mnexttoken.name == "--" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // else if
  } // if
  else if ( mnexttoken.type == CONSTANT ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
  } // else if
  else if ( mnexttoken.name == "(" ) {
    mtokenList.push_back( mnexttoken ) ;
    mnexttoken = scanner.Peektoken() ;
    Expression() ;
    if ( mnexttoken.name == ")" ) {
      mtokenList.push_back( mnexttoken ) ;
      mnexttoken = scanner.Peektoken() ;
    } // if
    else {
      throw mnexttoken ;
    } // else
  } // else if
  else {
    throw mnexttoken ;
  } // else

} // Parser::Unsigned_unary_exp()

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
  misdefined = false ;
  mtokenList.clear() ;
  mtempVariableList.clear() ;
  mtempFunctionParameter.clear() ;
} // Parser::Clear()





Token Scanner::Gettoken( Token token ) {
  return token ;
} // Scanner::Gettoken()

bool Scanner::Case1( char a ) {
  if ( a >= 'a' && a <= 'z' )
    return true ;
  if ( a >= 'A' && a <= 'Z' )
    return true ;
  if ( a == '_' )
    return true ;
  return false ;
} // Scanner::Case1()

bool Scanner::Case2( char a ) {
  if ( a == '.' || a == '"' || a == '\'' )
    return true ;

  if ( a >= '0' && a <= '9' )
    return true ;
  return false ;
} // Scanner::Case2()

bool Scanner::Case3( char b ) {
  if ( b == '_' ) 
    return false ;
  if ( b == '+' || b == '-' || b == '*' || b == '/' || b ==  '>' ||  
       b == '<' || b == '=' || b == '('  || b == '[' || b == ']' ||
       b == '{' || b == '}' || b == '%' || b == '^' || b == '&' || b == '!' ||
       b == '|' || b == ',' || b == '?' || b == ')' || b == ':' || b ==  ';' )
    return true ;
  return false ;
} // Scanner::Case3()

char Scanner::GetNextChar() {
  int n = 0 ;
  char a = '\0' ;
  if ( !scanf( "%c", &a ) )
    return '\0' ;
  if ( a == '\n' ) {
    gline++;
    gtempline++ ;
    gcol = 0 ;
  } // if
  else
  {
    gcol++;
  } // else
  
  return a ;
} // Scanner::GetNextChar()

bool Scanner::IsNum( char a ) {
  if ( a >= '0' && a <= '9' )
    return true ;
  if ( a == '_' )
    return true ;

  return false ;
} // Scanner::IsNum()

char Scanner::GetNextNonSpaceChar() {
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
} // Scanner::GetNextNonSpaceChar()

string Scanner::GetCaseOneToken( char a ) {
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
} // Scanner::GetCaseOneToken()

string Scanner::GetCaseTwoToken( char a ) {
  string temp = "" ;
  int dot = 0 ;
  char b = '\0' ;
  if ( a == '"' ) { 
    temp = temp + a ;
    a = GetNextChar() ;
    while ( a != '"' ) {
      temp = temp + a ;
      a = GetNextChar() ;
    } // while
    
    temp = temp + a ;
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
    temp = temp + a ;
    a = GetNextChar() ;
    while ( a != '\'' ) {
      temp = temp + a ;
      a = GetNextChar() ;
    } // while
    
    temp = temp + a ;
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
} // Scanner::GetCaseTwoToken()

string Scanner::GetCaseThreeToken( char a ) {
  string temp = "" ;
  char b = '\0' ;
  if ( a == '<' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' || b == '<' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // if
  } // if
  
  else if ( a == '>' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' || b == '>' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // if
  } // if
  
  else if ( a == '!' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '=' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '&' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '&' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if
    
  else if ( a == '|' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '|' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '=' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '+' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' || b == '+' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '-' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' || b == '-' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '*' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '/' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '%' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if

  else if ( a == '+' ) {
    b = cin.peek() ;
    temp = temp + a ;
    if ( b == '=' || b == '+' ) {
      a = GetNextChar() ;
      temp = temp + a ;
    } // else if
  } // else if


  else {
    temp = temp + a ;
  } // else
  
  return temp ;
} // Scanner::GetCaseThreeToken()

Token Scanner::Peektoken() {
  int over = 0 ;
  gtempline = -1 ;
  Token eof_token ;
  char tokenFirst = GetNextNonSpaceChar() ;
  if ( tokenFirst == '\0' ) {
    throw  over ;
    eof_token.name = "EOF" ;
    return eof_token ;
  } // if()
  
  Token token ;
  token.line = gline ;
  token.column = gcol ;
  bool isDivision = false ;
  char nextchar = '\0' ;
  char garbage = '\0' ;
  while ( tokenFirst == '/' && !isDivision ) {
    if ( tokenFirst == '/' ) {
      nextchar = cin.peek() ;
      if ( nextchar == '/' ) {
        while ( garbage != '\n' ) garbage = GetNextChar() ;
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
    token.type =  CONSTANT ;
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

  if ( token.name == "true" || token.name == "false" )
    token.type = CONSTANT ;
    /*
    if ( token.name == "+" || token.name == "-" )
      token.type = SIGN ;
    */
    
  if ( token.name == "else" || token.name == "while" || token.name == "if" || 
       token.name == "do" || token.name == "return" ) 
    token.type = SS ;
  return token ;


} // Scanner::Peektoken()



