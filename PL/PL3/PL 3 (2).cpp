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

struct Value {
  string str_value ;
  float num_value ;
  char char_value ;
  bool bool_value ;
  float num_array[100] ;
  string str_array[100] ;
  char char_array[100] ;
  VariableType type ;
};

struct Variable {
  VariableType type ;
  string name ;
  Value value ;
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
  void CAL_Type_specifier() ;
  void CAL_Rest_of_declarators() ;
  void CAL_Declaration() ;
  void CAL_Compound_statement() ;
  void CAL_Statement() ;
  void CAL_Expression( Value & value ) ;
  void CAL_Basic_expression( Value & value ) ;
  void CAL_Rest_of_Identifier_started_basic_exp( Value & value ) ;
  void CAL_Rest_of_PPMM_Identifier_started_basic_exp( Value & value, string op ) ;
  void CAL_Sign( Value & value ) ;
  void CAL_Actual_parameter_list( Value & value ) ;
  void CAL_Assignment_operator( Value & value ) ;
  void CAL_Romce_and_romloe( Value & value ) ;
  void CAL_Rest_of_maybe_logical_OR_exp( Value & value ) ;
  void CAL_Maybe_logical_AND_exp( Value & value ) ;
  void CAL_Rest_of_maybe_logical_AND_exp( Value & value ) ;
  void CAL_Maybe_bit_OR_exp( Value & value ) ;
  void CAL_Rest_of_maybe_bit_OR_exp( Value & value ) ;
  void CAL_Maybe_bit_ex_OR_exp( Value & value ) ;
  void CAL_Rest_of_maybe_bit_ex_OR_exp( Value & value ) ;
  void CAL_Maybe_bit_AND_exp( Value & value ) ;
  void CAL_Rest_of_maybe_bit_AND_exp( Value & value ) ;
  void CAL_Maybe_equality_exp( Value & value ) ;
  void CAL_Rest_of_maybe_equality_exp( Value & value ) ;
  void CAL_Maybe_relational_exp( Value & value ) ;
  void CAL_Rest_of_maybe_relational_exp( Value & value ) ;
  void CAL_Maybe_shift_exp( Value & value ) ;
  void CAL_Rest_of_maybe_shift_exp( Value & value ) ;
  void CAL_Maybe_additive_exp( Value & value ) ;
  void CAL_Rest_of_maybe_additive_exp( Value & value ) ;
  void CAL_Maybe_mult_exp( Value & value ) ;
  void CAL_Rest_of_maybe_mult_exp( Value & value ) ;
  void CAL_Unary_exp( Value & value ) ;
  void CAL_Signed_unary_exp( Value & value, string sign ) ;
  void CAL_Unsigned_unary_exp( Value & value ) ;
  void Skip_Type_specifier() ;
  void Skip_Rest_of_declarators() ;
  void Skip_Declaration() ;
  void Skip_Compound_statement() ;
  void Skip_Statement() ;
  void Skip_Expression() ;
  void Skip_Basic_expression() ;
  void Skip_Rest_of_Identifier_started_basic_exp() ;
  void Skip_Rest_of_PPMM_Identifier_started_basic_exp() ;
  void Skip_Sign() ;
  void Skip_Actual_parameter_list() ;
  void Skip_Assignment_operator() ;
  void Skip_Romce_and_romloe() ;
  void Skip_Rest_of_maybe_logical_OR_exp() ;
  void Skip_Maybe_logical_AND_exp() ;
  void Skip_Rest_of_maybe_logical_AND_exp() ;
  void Skip_Maybe_bit_OR_exp() ;
  void Skip_Rest_of_maybe_bit_OR_exp() ;
  void Skip_Maybe_bit_ex_OR_exp() ;
  void Skip_Rest_of_maybe_bit_ex_OR_exp() ;
  void Skip_Maybe_bit_AND_exp() ;
  void Skip_Rest_of_maybe_bit_AND_exp() ;
  void Skip_Maybe_equality_exp() ;
  void Skip_Rest_of_maybe_equality_exp() ;
  void Skip_Maybe_relational_exp() ;
  void Skip_Rest_of_maybe_relational_exp() ;
  void Skip_Maybe_shift_exp() ;
  void Skip_Rest_of_maybe_shift_exp() ;
  void Skip_Maybe_additive_exp() ;
  void Skip_Rest_of_maybe_additive_exp() ;
  void Skip_Maybe_mult_exp() ;
  void Skip_Rest_of_maybe_mult_exp() ;
  void Skip_Unary_exp() ;
  void Skip_Signed_unary_exp() ;
  void Skip_Unsigned_unary_exp() ;
  void Set_Variable_value( Value value, string ID ) ;
  void Print() ;
  void PrintString( string name ) ;
  Value IDvalue( string ID ) ;
  bool Havedot( string num ) ;
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
  string Process_string( string key ) ;
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
  bool misprint ; // 檢查遇到<<需不需要印 

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

string Parser::Process_string( string key ) {
  key.erase( 0, 1 ) ;
  key.erase( key.size() - 1, 1 ) ;
  return key ;
} // Parser::Process_string()

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
  else {
    CAL_Statement() ;
  } // else

   
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
      variable.value.type = Whattype( mtokenList[0].name ) ;
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
        mtempVariableList[i].value.type = Whattype( mtokenList[0].name ) ;
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

void Parser::PrintString( string name ) {
  char temp = '\0' ;
  for ( int i = 0 ; i < name.size() ; i++ ) {
    if ( name[i] == '\\' ) {
      if ( name[i + 1] == 'n' ) {
        cout << "\n" ;
        i++ ;
      } // if
    } // if
    else {
      cout << name[i] ;
    } // else
  } // for
} // Parser::PrintString()

void Parser::Set_Variable_value( Value value, string ID ) {
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( ID == mVariableList[i].name ) {
      mVariableList[i].value = value ;
    } // if
  } // for
} // Parser::Set_Variable_value()

Value Parser::IDvalue( string ID ) {
  Value value ;
  value.bool_value = false ;
  value.char_value = '\0' ;
  value.num_value = 0 ;
  value.str_value = "" ;
  value.type = NO ;
  for ( int i = 0 ; i < mVariableList.size() ; i++ ) {
    if ( ID == mVariableList[i].name ) {
      // misfloat = mVariableList[i].isfloat ;
      return mVariableList[i].value ;
    } // if
  } // for
  
  return value ;
} // Parser::IDvalue()

void Parser::CAL_Type_specifier() {

  if ( mtokenList[mindex].name == "int" || mtokenList[mindex].name == "char" || 
       mtokenList[mindex].name == "float" || 
       mtokenList[mindex].name == "string" || mtokenList[mindex].name == "bool" ) {
    mindex++ ;
  } // if

} // Parser::CAL_Type_specifier()

void Parser::CAL_Rest_of_declarators() {

  if ( mtokenList[mindex].name == "[" ) {
    
    mindex++ ; 
    if ( mtokenList[mindex].type == CONSTANT ) {
      mindex++ ;
      if ( mtokenList[mindex].name == "]" ) {
        mindex++ ;
      } // if

    } // if

  } // if

  while ( mtokenList[mindex].name == "," ) {

    mindex++ ;
    if ( mtokenList[mindex].type == IDENT ) {

      mindex++ ;
    } // if


    if ( mtokenList[mindex].name == "[" ) {
      mindex++ ;
      if ( mtokenList[mindex].type == CONSTANT ) {
        mindex++ ;
        if ( mtokenList[mindex].name == "]" ) {
          mindex++ ;
        } // if

      } // if
    } // if

  } // while
  
  if ( mtokenList[mindex].name == ";" ) {
    mindex++ ;
  } // if

} // Parser::CAL_Rest_of_declarators()

void Parser::CAL_Compound_statement() {

  if ( mtokenList[mindex].name == "{" ) {
    mindex++ ;

    while ( mtokenList[mindex].name != "}" ) {
      if ( mtokenList[mindex].name == "int" || mtokenList[mindex].name == "char" || 
           mtokenList[mindex].name == "float" || mtokenList[mindex].name == "string" || 
           mtokenList[mindex].name == "bool" ) {
        CAL_Declaration() ;
      } // if
      else {
        CAL_Statement() ;
      } // else

    } // while  有可能卡無窮 我不知道這樣寫可不可以
    
    if ( mtokenList[mindex].name == "}" ) {
      mindex++ ;
    } // if
  } // if

} // Parser::CAL_Compound_statement()

void Parser::CAL_Declaration() {

  CAL_Type_specifier() ;
  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    
    CAL_Rest_of_declarators() ;
  } // if

} // Parser::CAL_Declaration()

void Parser::CAL_Statement() {
  misprint = true ;
  mindex = 0 ;
  Value value ;
  value.bool_value = false ;
  value.char_value = '\0' ;
  value.num_value = 0 ;
  value.str_value = "" ;
  value.type = NO ;
  if ( mtokenList[mindex].name == ";" ) {
    mindex++ ;
  } // if
  else if ( mtokenList[mindex].name == "return" ) {

    mindex++ ;
    if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
         mtokenList[mindex].name == "--"  || mtokenList[mindex].name == "+" || 
         mtokenList[mindex].name == "-" || mtokenList[mindex].name == "!" 
         || mtokenList[mindex].type == CONSTANT || mtokenList[mindex].name == "(" )
      CAL_Expression( value ) ; // 我不太確定條件要放啥 可能有問題
    if ( mtokenList[mindex].name == ";" ) {
      mindex++ ;
    } // if

  } // else if
  else if ( mtokenList[mindex].name == "if" ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      misprint = false ;
      mindex++ ;
      CAL_Expression( value ) ;
      if ( mtokenList[mindex].name == ")" ) {
        misprint = true ;
        mindex++ ;
      } // if
    
      CAL_Statement() ;
      if ( mtokenList[mindex].name == "else" ) {
        mindex++ ;
        CAL_Statement() ;
      } // if
    } // if
  } // else if
  else if ( mtokenList[mindex].name == "while" ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      misprint = false ;
      mindex++ ;
      CAL_Expression( value ) ;
      if ( mtokenList[mindex].name == ")" ) {
        misprint = true ;
        mindex++ ;
      } // if
      
      CAL_Statement() ;
    } // if
  } // else if
  else if ( mtokenList[mindex].name == "do" ) {
    mindex++ ;
    CAL_Statement() ;
    if ( mtokenList[mindex].name == "while" ) {
      mindex++ ;
      if ( mtokenList[mindex].name == "(" ) {
        misprint = false ;
        mindex++ ;
        CAL_Expression( value ) ;
        if ( mtokenList[mindex].name == ")" ) {
          misprint = true ;
          mindex++ ;
          if ( mtokenList[mindex].name == ";" ) {
            mindex++ ;
          } // if
        } // if

      } // if

    } // if
  } // else if
  else if ( mtokenList[mindex].name == "{" ) {
    CAL_Compound_statement() ;
  } // else if
  else {
    CAL_Expression( value ) ;
    if ( mtokenList[mindex].name == ";" ) {
      mindex++ ;
    } // if
  } // else
} // Parser::CAL_Statement()

void Parser::CAL_Expression( Value & value ) {

  CAL_Basic_expression( value ) ;
  while ( mtokenList[mindex].name == "," ) {
    mindex++ ;
    CAL_Basic_expression( value ) ;
  } // while
} // Parser::CAL_Expression()

void Parser::CAL_Basic_expression( Value & value ) {
  string temp = "" ;
  if ( mtokenList[mindex].type == IDENT ) {
    value = IDvalue( mtokenList[mindex].name ) ; // 變數要被assign過才會有確切值 
    mindex++ ;
    CAL_Rest_of_Identifier_started_basic_exp( value ) ;
  } // if
  else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
    mindex++ ;
    if ( mtokenList[mindex].type == IDENT ) {

      mindex++ ;
      CAL_Rest_of_PPMM_Identifier_started_basic_exp( value, mtokenList[mindex].name ) ;
    } // if
  } // else if
  else if ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-"  || 
            mtokenList[mindex].name == "!" ) {
    temp = mtokenList[mindex].name ;
    CAL_Sign( value ) ;
    while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
            mtokenList[mindex].name == "!" ) {
      CAL_Sign( value ) ;
    } // while
    
    CAL_Signed_unary_exp( value, temp ) ;
    CAL_Romce_and_romloe( value ) ;

  } // else if
  else if ( mtokenList[mindex].type == CONSTANT ) {
    if ( mtokenList[mindex].name[0] == '"' ) {
      value.str_value = mtokenList[mindex].name ;
      value.type = STRING ;
    } // if
    else if ( mtokenList[mindex].name[0] == '\'' ) {
      value.char_value = mtokenList[mindex].name[1] ; // 還沒考慮反斜線 
      value.type = CHAR ;
    } // else if
    else if ( mtokenList[mindex].name == "true" || mtokenList[mindex].name == "false" ) {
      if ( mtokenList[mindex].name == "true" )
        value.bool_value = true ;
      else if ( mtokenList[mindex].name == "false" )
        value.bool_value = false ;
      value.type = BOOL ;
    } // else if
    else {
      value.num_value = atof( mtokenList[mindex].name.c_str() ) ;
      if ( Havedot( mtokenList[mindex].name ) )
        value.type = FLOAT ;
      else
        value.type = INT ;
    } // else

    mindex++ ;
    CAL_Romce_and_romloe( value ) ;
  } // else if
  else if ( mtokenList[mindex].name == "(" ) {
    misprint = false ;
    mindex++ ;
    CAL_Expression( value ) ;
    if ( mtokenList[mindex].name == ")" ) {
      mindex++ ;
    } // if

    misprint = true ;
    CAL_Romce_and_romloe( value ) ;
  } // else if
} // Parser::CAL_Basic_expression()

void Parser::CAL_Rest_of_Identifier_started_basic_exp( Value & value ) {
  bool isarray = false ;
  string op = "" ; 
  string tempID = "" ;
  string double_quote = "\"" ;
  string m = "" ;
  string n = "" ;
  Value tempvalue ;
  int i = 0 ;
  int j = 0 ;
  int index = 0 ;
  if ( mtokenList[mindex].name == "[" ) {
    isarray = true ;
    tempID = mtokenList[mindex - 1].name ;
    mindex++ ;
    CAL_Expression( value ) ;
    index = value.num_value ;
    if ( mtokenList[mindex].name == "]" ) {
      mindex++ ;
    } // if


    if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
      op = mtokenList[mindex].name ;
      value = IDvalue( tempID ) ;
      tempvalue = IDvalue( tempID ) ;
      mindex++ ;
      if ( tempvalue.type == INT || tempvalue.type == FLOAT ) {
        value.type = tempvalue.type ;
        value.num_value = tempvalue.num_array[index] ;
      } // if
      else if ( tempvalue.type == STRING ) {
        value.type = tempvalue.type ;
        value.str_value = tempvalue.str_array[index] ;
      } // else if
      else if ( tempvalue.type == CHAR ) {
        value.type = tempvalue.type ;
        value.char_value = tempvalue.char_array[index] ;
      } // else if

      CAL_Romce_and_romloe( value ) ;

      
      if ( op == "++" ) {
        tempvalue.num_array[index]++ ;
        Set_Variable_value( tempvalue, tempID ) ;
      } // if
      else if ( op == "--" ) {
        tempvalue.num_array[index]-- ;
        Set_Variable_value( tempvalue, tempID ) ;
      } // if
    } // if
    else if ( mtokenList[mindex].name == "+=" || mtokenList[mindex].name == "-=" || 
              mtokenList[mindex].name == "*=" || mtokenList[mindex].name == "/=" || 
              mtokenList[mindex].name == "%=" || mtokenList[mindex].name == "=" ) {
      op = mtokenList[mindex].name ;
      CAL_Assignment_operator( value ) ;
      CAL_Basic_expression( value ) ;
      tempvalue = value ;
      value = IDvalue( tempID ) ;
      if ( op == "=" ) {
        if ( value.type == INT || value.type == FLOAT ) {
          value.num_array[index] = tempvalue.num_value ;
          Set_Variable_value( value, tempID ) ;
          value.num_value = value.num_array[index] ;
        } // if
        else if ( value.type == STRING ) {
          value.str_array[index] = tempvalue.str_value ;
          Set_Variable_value( value, tempID ) ;
          value.str_value = value.str_array[index] ;
        } // else if
        else if ( value.type == CHAR ) {
          value.char_array[index] = tempvalue.char_value ;
          Set_Variable_value( value, tempID ) ;
          value.char_value = value.char_array[index] ;
        } // else if
      } // if
      else if ( op == "+=" ) {
        if ( value.type == INT || value.type == FLOAT ) {
          value.num_array[index] += tempvalue.num_value ;
          Set_Variable_value( value, tempID ) ;
          value.num_value = value.num_array[index] ;
        } // if
        else if ( value.type == STRING ) {
          m = Process_string( value.str_array[index] ) ;
          n = Process_string( tempvalue.str_value ) ;
          m += n ;
          m = double_quote + m + double_quote ;
          value.str_array[index] = m ;
          Set_Variable_value( value, tempID ) ;
          value.str_value = value.str_array[index] ;
        } // else if  沒有考慮到陣列不同型別相加 
      } // else if
      else if ( op == "-=" ) {
        value.num_array[index] -= tempvalue.num_value ;
        Set_Variable_value( value, tempID ) ;
        value.num_value = value.num_array[index] ;
      } // else if
      else if ( op == "*=" ) {
        value.num_array[index] *= tempvalue.num_value ;
        Set_Variable_value( value, tempID ) ;
        value.num_value = value.num_array[index] ;
      } // else if
      else if ( op == "/=" ) {
        value.num_array[index] /= tempvalue.num_value ;
        Set_Variable_value( value, tempID ) ;
        value.num_value = value.num_array[index] ;
      } // else if
      else if ( op == "%=" ) {
        i = value.num_array[index] ;
        j = tempvalue.num_array[index] ;
        i %= j ;
        value.num_array[index] = i ;
        Set_Variable_value( value, tempID ) ;
        value.num_value = value.num_array[index] ;
      } // else if
    } // else if
    else {
      tempvalue = IDvalue( tempID ) ;
      if ( tempvalue.type == INT || tempvalue.type == FLOAT ) {
        value.type = tempvalue.type ;
        value.num_value = tempvalue.num_array[index] ;
      } // if
      else if ( tempvalue.type == STRING ) {
        value.type = tempvalue.type ;
        value.str_value = tempvalue.str_array[index] ;
      } // else if
      else if ( tempvalue.type == CHAR ) {
        value.type = tempvalue.type ;
        value.char_value = tempvalue.char_array[index] ;
      } // else if

      CAL_Romce_and_romloe( value ) ;
    } // else
  } // if  陣列 

  else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
    tempID = mtokenList[mindex - 1].name ;
    op = mtokenList[mindex].name ;
    mindex++ ;
    value = IDvalue( tempID ) ;
    CAL_Romce_and_romloe( value ) ;
    tempvalue = value ;
    value = IDvalue( tempID ) ;
    if ( op == "++" )
      value.num_value++ ;
    else if ( op == "--" )
      value.num_value-- ;
    Set_Variable_value( value, tempID ) ;

    value = tempvalue ;
  } // else if
    
  else if ( mtokenList[mindex].name == "+=" || mtokenList[mindex].name == "-=" || 
            mtokenList[mindex].name == "*=" || mtokenList[mindex].name == "/=" || 
            mtokenList[mindex].name == "%=" || mtokenList[mindex].name == "=" ) {
    tempID = mtokenList[mindex - 1].name ;
    op = mtokenList[mindex].name ;
    CAL_Assignment_operator( value ) ;
    CAL_Basic_expression( value ) ;
    if ( op == "+=" ) {
      tempvalue = IDvalue( tempID ) ;
      if ( value.type == STRING ) {
        m = Process_string( tempvalue.str_value ) ;
        n = Process_string( value.str_value ) ;
        m += n ;
        m = double_quote + m + double_quote ;
        tempvalue.type = STRING ;
        tempvalue.str_value = m ;

      } // if
      else if ( value.type == CHAR ) {
        m = Process_string( tempvalue.str_value ) ;
        m += value.char_value ;
        m = double_quote + m + double_quote ;
        tempvalue.type = STRING ;
        tempvalue.str_value = m ;
      } // else if
      else
        tempvalue.num_value += value.num_value ;


      Set_Variable_value( tempvalue, tempID ) ;
      value = tempvalue ;
    } // if
    else if ( op == "*=" ) {
      tempvalue = IDvalue( tempID ) ;
      tempvalue.num_value *= value.num_value ;
      Set_Variable_value( tempvalue, tempID ) ;
      value = tempvalue ;
    } // else if
    else if ( op == "%=" ) {
      i = tempvalue.num_value ;
      j = value.num_value ;
      tempvalue = IDvalue( tempID ) ;
      i %= j ;
      tempvalue.num_value = i ;
      Set_Variable_value( tempvalue, tempID ) ;
      value = tempvalue ;
    } // else if
    else if ( op == "-=" ) {
      tempvalue = IDvalue( tempID ) ;
      tempvalue.num_value -= value.num_value ;
      Set_Variable_value( tempvalue, tempID ) ;
      value = tempvalue ;
    } // else if
    else if ( op == "/=" ) {
      tempvalue = IDvalue( tempID ) ;
      tempvalue.num_value /= value.num_value ;
      Set_Variable_value( tempvalue, tempID ) ;
      value = tempvalue ;
    } // else if
    else if ( op == "=" )
      Set_Variable_value( value, tempID ) ; // 不確定mindex-1會不會有問題發生 
    // cout << value.num_value ;
  } // else if

  else if ( mtokenList[mindex].name == "(" ) {
    misprint = false ;
    mindex++ ;
    if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
         mtokenList[mindex].name == "--" || 
         mtokenList[mindex].name == "+" || mtokenList[mindex].name == "!" ||
         mtokenList[mindex].name == "-" || mtokenList[mindex].type == CONSTANT || 
         mtokenList[mindex].name == "(" ) {
      CAL_Actual_parameter_list( value ) ;
    } // if
    
    if ( mtokenList[mindex].name == ")" ) {
      misprint = true ;
      mindex++ ;
    } // if
    
    CAL_Romce_and_romloe( value ) ;
  } // else if
  else {
    CAL_Romce_and_romloe( value ) ;
  } // else
} // Parser::CAL_Rest_of_Identifier_started_basic_exp()

void Parser::CAL_Rest_of_PPMM_Identifier_started_basic_exp( Value & value, string op ) {
  bool isarray = false ;
  Value tempvalue ;
  int index  = 0 ;
  string tempID = mtokenList[mindex - 1].name ;
  value = IDvalue( tempID ) ;
  if ( mtokenList[mindex].name == "[" ) {
    isarray = true ;
    mindex++ ;
    CAL_Expression( value ) ;
    index = value.num_value ;
    if ( mtokenList[mindex].name == "]" ) {
      mindex++ ;
    } // if
    
    tempvalue = IDvalue( tempID ) ;
    if ( tempvalue.type == INT || tempvalue.type == FLOAT ) {
      value.type = tempvalue.type ;
      value.num_value = tempvalue.num_array[index] ;
    } // if
    else if ( tempvalue.type == STRING ) {
      value.type = tempvalue.type ;
      value.str_value = tempvalue.str_array[index] ;
    } // else if
    else if ( tempvalue.type == CHAR ) {
      value.type = tempvalue.type ;
      value.char_value = tempvalue.char_array[index] ;
    } // else if
  } // if


  if ( op == "++" ) {
    value.num_value++ ;
    tempvalue.num_array[index]++ ;
  } // if
  else if ( op == "--" ) {
    value.num_value-- ;
    tempvalue.num_array[index]-- ;
  } // else if

  if ( isarray )
    Set_Variable_value( tempvalue, tempID ) ;
  else
    Set_Variable_value( value, tempID ) ;

  CAL_Romce_and_romloe( value ) ;
} // Parser::CAL_Rest_of_PPMM_Identifier_started_basic_exp()

void Parser::CAL_Sign( Value & value ) {

  if ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || mtokenList[mindex].name == "!" ) {
    mindex++ ;
  } // if

} // Parser::CAL_Sign()

void Parser::CAL_Actual_parameter_list( Value & value ) {

  CAL_Basic_expression( value ) ;
  while ( mtokenList[mindex].name == "," ) {
    mindex++ ;
    CAL_Basic_expression( value ) ;
  } // while
} // Parser::CAL_Actual_parameter_list()

void Parser::CAL_Assignment_operator( Value & value ) {

  if ( mtokenList[mindex].name == "+=" || mtokenList[mindex].name == "-=" || 
       mtokenList[mindex].name == "*=" || 
       mtokenList[mindex].name == "/=" || mtokenList[mindex].name == "%=" || 
       mtokenList[mindex].name == "=" ) {
    mindex++ ;
  } // if

} // Parser::CAL_Assignment_operator()

void Parser::CAL_Romce_and_romloe( Value & value ) {

  CAL_Rest_of_maybe_logical_OR_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  Value tempvalue2 ;
  tempvalue = value ;
  if ( mtokenList[mindex].name == "?" ) {
    mindex++ ;

    if ( tempvalue.bool_value )
      CAL_Basic_expression( value ) ;
    else
      Skip_Basic_expression() ;
    if ( mtokenList[mindex].name == ":" ) {


      mindex++ ;
      if ( !tempvalue.bool_value )
        CAL_Basic_expression( value ) ;
      else
        Skip_Basic_expression() ;
    } // if


    // 還沒搞懂這要怎麼寫 
  } // if
} // Parser::CAL_Romce_and_romloe()

void Parser::CAL_Rest_of_maybe_logical_OR_exp( Value & value ) {
  CAL_Rest_of_maybe_logical_AND_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "||" ) {
    mindex++ ;
    CAL_Maybe_logical_AND_exp( value ) ;
    if ( oper == "||" ) {
      value.bool_value = tempvalue.bool_value || value.bool_value ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Rest_of_maybe_logical_OR_exp()

void Parser::CAL_Maybe_logical_AND_exp( Value & value ) {

  CAL_Maybe_bit_OR_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "&&" ) {
    mindex++ ;
    CAL_Maybe_bit_OR_exp( value ) ;
    if ( oper == "&&" ) {
      value.bool_value = tempvalue.bool_value && value.bool_value ;
      value.type = BOOL ;
    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while

} // Parser::CAL_Maybe_logical_AND_exp()

void Parser::CAL_Rest_of_maybe_logical_AND_exp( Value & value ) {

  CAL_Rest_of_maybe_bit_OR_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "&&" ) {
    mindex++ ;
    CAL_Maybe_bit_OR_exp( value ) ;
    if ( oper == "&&" ) {
      value.bool_value = tempvalue.bool_value && value.bool_value ;
      value.type = BOOL ;
    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Rest_of_maybe_logical_AND_exp()

void Parser::CAL_Maybe_bit_OR_exp( Value & value ) {

  CAL_Maybe_bit_ex_OR_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "|" ) {
    mindex++ ;
    CAL_Maybe_bit_ex_OR_exp( value ) ;
    if ( oper == "|" )
      ; // value.bool_value = tempvalue.bool_value | value.bool_value ;


    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while


} // Parser::CAL_Maybe_bit_OR_exp()

void Parser::CAL_Rest_of_maybe_bit_OR_exp( Value & value ) {

  CAL_Rest_of_maybe_bit_ex_OR_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "|" ) {
    mindex++ ;
    CAL_Maybe_bit_ex_OR_exp( value ) ;
    if ( oper == "|" )
      ; // value.bool_value = tempvalue.bool_value | value.bool_value ;


    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while

} // Parser::CAL_Rest_of_maybe_bit_OR_exp()

void Parser::CAL_Maybe_bit_ex_OR_exp( Value & value ) {

  CAL_Maybe_bit_AND_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "^" ) {
    mindex++ ;
    CAL_Maybe_bit_AND_exp( value ) ;
    if ( oper == "^" )
      ; // value.bool_value = tempvalue.bool_value ^ value.bool_value ;


    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while

} // Parser::CAL_Maybe_bit_ex_OR_exp()

void Parser::CAL_Rest_of_maybe_bit_ex_OR_exp( Value & value ) {

  CAL_Rest_of_maybe_bit_AND_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "^" ) {
    mindex++ ;
    CAL_Maybe_bit_AND_exp( value ) ;
    if ( oper == "^" )
      ; // value.bool_value = tempvalue.bool_value ^ value.bool_value ;


    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
  
} // Parser::CAL_Rest_of_maybe_bit_ex_OR_exp()

void Parser::CAL_Maybe_bit_AND_exp( Value & value ) {

  CAL_Maybe_equality_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "&" ) {
    mindex++ ;
    CAL_Maybe_equality_exp( value ) ;
    if ( oper == "&" )
      ; // value.bool_value = tempvalue.bool_value & value.bool_value ;

    if ( value.num_value == 1 ) {
      value.bool_value = true ;
      value.type = BOOL ;
    } // if
    else if ( value.num_value == 0 ) {
      value.bool_value = false ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
  

} // Parser::CAL_Maybe_bit_AND_exp()

void Parser::CAL_Rest_of_maybe_bit_AND_exp( Value & value ) {

  CAL_Rest_of_maybe_equality_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "&" ) {
    mindex++ ;
    CAL_Maybe_equality_exp( value ) ;
    if ( oper == "&" )
      ; // value.bool_value = tempvalue.bool_value & value.bool_value ;

    if ( value.num_value == 1 ) {
      value.bool_value = true ;
      value.type = BOOL ;
    } // if
    else if ( value.num_value == 0 ) {
      value.bool_value = false ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
  

} // Parser::CAL_Rest_of_maybe_bit_AND_exp()

void Parser::CAL_Maybe_equality_exp( Value & value ) {

  CAL_Maybe_relational_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "==" || mtokenList[mindex].name == "!=" ) {
    mindex++ ;
    CAL_Maybe_relational_exp( value ) ;
    if ( oper == "==" && value.type == STRING ) {
      if ( tempvalue.str_value == value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == STRING ) {
      if ( tempvalue.str_value != value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "==" && value.type == FLOAT ) {
      if ( tempvalue.num_value == value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == FLOAT ) {
      if ( tempvalue.num_value != value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "==" && value.type == CHAR ) {
      if ( tempvalue.char_value == value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == CHAR ) {
      if ( tempvalue.char_value != value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "==" && value.type == INT ) {
      if ( tempvalue.num_value == value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == INT ) {
      if ( tempvalue.num_value != value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if

    if ( value.num_value == 1 ) {
      value.bool_value = true ;
      value.type = BOOL ;
    } // if
    else if ( value.num_value == 0 ) {
      value.bool_value = false ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
  

} // Parser::CAL_Maybe_equality_exp()

void Parser::CAL_Rest_of_maybe_equality_exp( Value & value ) {

  CAL_Rest_of_maybe_relational_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "==" || mtokenList[mindex].name == "!=" ) {
    mindex++ ;
    CAL_Maybe_relational_exp( value ) ;
    if ( oper == "==" && value.type == STRING ) {
      if ( tempvalue.str_value == value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == STRING ) {
      if ( tempvalue.str_value != value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "==" && value.type == FLOAT ) {
      if ( tempvalue.num_value == value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == FLOAT ) {
      if ( tempvalue.num_value != value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "==" && value.type == CHAR ) {
      if ( tempvalue.char_value == value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == CHAR ) {
      if ( tempvalue.char_value != value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "==" && value.type == INT ) {
      if ( tempvalue.num_value == value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "!=" && value.type == INT ) {
      if ( tempvalue.num_value != value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if

    if ( value.num_value == 1 ) {
      value.bool_value = true ;
      value.type = BOOL ;
    } // if
    else if ( value.num_value == 0 ) {
      value.bool_value = false ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while

} // Parser::CAL_Rest_of_maybe_equality_exp()

void Parser::CAL_Maybe_relational_exp( Value & value ) {
  CAL_Maybe_shift_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == ">" || mtokenList[mindex].name == "<" || 
          mtokenList[mindex].name == ">=" || mtokenList[mindex].name == "<=" ) {
    mindex++ ;
    CAL_Maybe_shift_exp( value ) ;
    if ( oper == ">" && value.type == STRING ) {
      if ( tempvalue.str_value > value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == STRING ) {
      if ( tempvalue.str_value < value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == STRING ) {
      if ( tempvalue.str_value >= value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == STRING ) {
      if ( tempvalue.str_value <= value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">" && value.type == FLOAT ) {
      if ( tempvalue.num_value > value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == FLOAT ) {
      if ( tempvalue.num_value < value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == FLOAT ) {
      if ( tempvalue.num_value >= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == FLOAT ) {
      if ( tempvalue.num_value <= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">" && value.type == CHAR ) {
      if ( tempvalue.char_value > value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == CHAR ) {
      if ( tempvalue.char_value < value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == CHAR ) {
      if ( tempvalue.char_value >= value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == CHAR ) {
      if ( tempvalue.char_value <= value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">" && value.type == INT ) {
      if ( tempvalue.num_value > value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == INT ) {
      if ( tempvalue.num_value < value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == INT ) {
      if ( tempvalue.num_value >= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == INT ) {
      if ( tempvalue.num_value <= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if

    if ( value.num_value == 1 ) {
      value.bool_value = true ;
      value.type = BOOL ;
    } // if
    else if ( value.num_value == 0 ) {
      value.bool_value = false ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
  

} // Parser::CAL_Maybe_relational_exp()

void Parser::CAL_Rest_of_maybe_relational_exp( Value & value ) {

  CAL_Rest_of_maybe_shift_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == ">" || mtokenList[mindex].name == "<" || 
          mtokenList[mindex].name == ">=" || mtokenList[mindex].name == "<=" ) {
    mindex++ ;
    CAL_Maybe_shift_exp( value ) ;
    if ( oper == ">" && value.type == STRING ) {
      if ( tempvalue.str_value > value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == STRING ) {
      if ( tempvalue.str_value < value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == STRING ) {
      if ( tempvalue.str_value >= value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == STRING ) {
      if ( tempvalue.str_value <= value.str_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">" && value.type == FLOAT ) {
      if ( tempvalue.num_value > value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == FLOAT ) {
      if ( tempvalue.num_value < value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == FLOAT ) {
      if ( tempvalue.num_value >= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == FLOAT ) {
      if ( tempvalue.num_value <= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">" && value.type == CHAR ) {
      if ( tempvalue.char_value > value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == CHAR ) {
      if ( tempvalue.char_value < value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == CHAR ) {
      if ( tempvalue.char_value >= value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == CHAR ) {
      if ( tempvalue.char_value <= value.char_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">" && value.type == INT ) {
      if ( tempvalue.num_value > value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // if
    else if ( oper == "<" && value.type == INT ) {
      if ( tempvalue.num_value < value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == ">=" && value.type == INT ) {
      if ( tempvalue.num_value >= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if
    else if ( oper == "<=" && value.type == INT ) {
      if ( tempvalue.num_value <= value.num_value ) {
        value.num_value = 1 ;
        value.type = FLOAT ;
      } // if
      else {
        value.num_value = 0 ;
        value.type = FLOAT ;
      } // else
    } // else if

    if ( value.num_value == 1 ) {
      value.bool_value = true ;
      value.type = BOOL ;
    } // if
    else if ( value.num_value == 0 ) {
      value.bool_value = false ;
      value.type = BOOL ;

    } // if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while

} // Parser::CAL_Rest_of_maybe_relational_exp()

void Parser::CAL_Maybe_shift_exp( Value & value ) {
  int i = 0 ;
  int j = 0 ;
  int tempnum = 0 ;
  string temp = "" ;
  CAL_Maybe_additive_exp( value ) ;
  string oper = "" ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "<<" || mtokenList[mindex].name == ">>" ) {
    mindex++ ;
    CAL_Maybe_additive_exp( value ) ;
    if ( mtokenList[0].name == "cout" && value.type == STRING && misprint ) {
      temp = value.str_value ;
      temp.erase( 0, 1 ) ;
      temp.erase( temp.size() - 1, 1 ) ;
      PrintString( temp ) ;

    } // if
    else if ( mtokenList[0].name == "cout" && value.type == INT && misprint )
      cout << value.num_value ;
    else if ( mtokenList[0].name == "cout" && value.type == FLOAT && misprint )
      cout << value.num_value ;
    else if ( mtokenList[0].name == "cout" && value.type == CHAR && misprint )
      cout << value.char_value ;
    else if ( mtokenList[0].name == "cout" && value.type == BOOL && misprint ) {
      if ( value.bool_value )
        cout << "true" ;
      else if ( !value.bool_value )
        cout << "false" ;
    } // else if
    else if ( oper == "<<" ) {
      i = tempvalue.num_value ;
      j = value.num_value ;
      tempnum = i << j ; // value.num_value = int( tempvalue.num_value ) << int( value.num_value ) ;
      value.num_value = tempnum ;

    } // else if
    else if ( oper == ">>" ) {
      i = tempvalue.num_value ;
      j = value.num_value ;
      tempnum = i >> j ; // value.num_value = int( tempvalue.num_value ) >> int( value.num_value ) ; 
      value.num_value = tempnum ;
    } // else if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Maybe_shift_exp()

void Parser::CAL_Rest_of_maybe_shift_exp( Value & value ) {
  int i = 0 ;
  int j = 0 ;
  int tempnum = 0 ;
  string temp = "" ;
  CAL_Rest_of_maybe_additive_exp( value ) ;
  string oper = "" ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "<<" || mtokenList[mindex].name == ">>" ) {
    mindex++ ;
    CAL_Maybe_additive_exp( value ) ;
    if ( mtokenList[0].name == "cout" && value.type == STRING && misprint ) {
      temp = value.str_value ;
      temp.erase( 0, 1 ) ;
      temp.erase( temp.size() - 1, 1 ) ;
      PrintString( temp ) ;
    } // if
    else if ( mtokenList[0].name == "cout" && value.type == INT && misprint )
      cout << value.num_value ;
    else if ( mtokenList[0].name == "cout" && value.type == FLOAT && misprint )
      cout << value.num_value ;
    else if ( mtokenList[0].name == "cout" && value.type == CHAR && misprint )
      cout << value.char_value ;
    else if ( mtokenList[0].name == "cout" && value.type == BOOL && misprint ) {
      if ( value.bool_value )
        cout << "true" ;
      else if ( !value.bool_value )
        cout << "false" ;
    } // else if
    else if ( oper == "<<" ) {
      i = tempvalue.num_value ;
      j = value.num_value ;
      tempnum = i << j ; // value.num_value = int( tempvalue.num_value ) << int( value.num_value ) ;
      value.num_value = tempnum ;
    } // else if
    else if ( oper == ">>" ) {
      i = tempvalue.num_value ;
      j = value.num_value ;
      tempnum = i >> j ; // value.num_value = int( tempvalue.num_value ) >> int( value.num_value ) ; 
      value.num_value = tempnum ;
    } // else if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Rest_of_maybe_shift_exp() 

void Parser::CAL_Maybe_additive_exp( Value & value ) {

  string double_quote = "\"" ;
  CAL_Maybe_mult_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" ) {
    mindex++ ;
    CAL_Maybe_mult_exp( value ) ;
    if ( oper == "+" && value.type == STRING ) {
      value.str_value = Process_string( tempvalue.str_value ) + Process_string( value.str_value ) ;
      value.str_value = double_quote + value.str_value + double_quote ;
      value.type = STRING ;
    } // if
    else if ( oper == "+" && value.type == CHAR ) {
      value.str_value = Process_string( tempvalue.str_value ) + value.char_value ;
      value.str_value = double_quote + value.str_value + double_quote ;
      value.type = STRING ;
    } // else if
    else if ( oper == "+" ) {
      value.num_value = tempvalue.num_value + value.num_value ;
      if ( tempvalue.type == INT && value.type == INT )
        value.type = INT ;
      else
        value.type = FLOAT ;
    } // else if
    else if ( oper == "-" ) {
      value.num_value = tempvalue.num_value - value.num_value ;
      if ( tempvalue.type == INT && value.type == INT )
        value.type = INT ;
      else
        value.type = FLOAT ;
    } // else if

    
    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Maybe_additive_exp()

void Parser::CAL_Rest_of_maybe_additive_exp( Value & value ) {
  string double_quote = "\"" ;
  CAL_Rest_of_maybe_mult_exp( value ) ;
  string oper ;
  oper = mtokenList[mindex].name ;
  Value tempvalue ;
  tempvalue = value ;
  while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" ) {
    mindex++ ;
    CAL_Maybe_mult_exp( value ) ;
    if ( oper == "+" && value.type == STRING ) {
      value.str_value = Process_string( tempvalue.str_value ) + Process_string( value.str_value ) ;
      value.str_value = double_quote + value.str_value + double_quote ;
      value.type = STRING ;
    } // if
    else if ( oper == "+" && value.type == CHAR ) {
      value.str_value = Process_string( tempvalue.str_value ) + value.char_value ;
      value.str_value = double_quote + value.str_value + double_quote ;
      value.type = STRING ;
    } // else if
    else if ( oper == "+" ) {
      value.num_value = tempvalue.num_value + value.num_value ;
      if ( tempvalue.type == INT && value.type == INT )
        value.type = INT ;
      else
        value.type = FLOAT ;
    } // else if
    else if ( oper == "-" ) {
      value.num_value = tempvalue.num_value - value.num_value ;
      if ( tempvalue.type == INT && value.type == INT )
        value.type = INT ;
      else
        value.type = FLOAT ;
    } // else if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Rest_of_maybe_additive_exp()

void Parser::CAL_Maybe_mult_exp( Value & value ) {
  CAL_Unary_exp( value ) ;
  CAL_Rest_of_maybe_mult_exp( value ) ;
} // Parser::CAL_Maybe_mult_exp()

void Parser::CAL_Rest_of_maybe_mult_exp( Value & value ) {
  Value tempvalue ;
  tempvalue = value ;
  string oper ;
  int tempnum = 0 ;
  int i = 0 ;
  int j = 0 ;
  oper = mtokenList[mindex].name ;
  while ( mtokenList[mindex].name == "*" || mtokenList[mindex].name == "/" || 
          mtokenList[mindex].name == "%" ) {
    mindex++ ;
    CAL_Unary_exp( value ) ;
    if ( oper == "*" ) {
      value.num_value = tempvalue.num_value * value.num_value ;
      if ( tempvalue.type == INT && value.type == INT ) {
        value.type = INT ;
        tempnum = value.num_value ;
        value.num_value = tempnum ;
      } // if
      else
        value.type = FLOAT ;
    } // if
    else if ( oper == "/" ) {
      value.num_value = tempvalue.num_value / value.num_value ;
      if ( tempvalue.type == INT && value.type == INT ) {
        value.type = INT ;
        tempnum = value.num_value ;
        value.num_value = tempnum ;
      } // if
      else
        value.type = FLOAT ;
    } // else if
    else if ( oper == "%" ) {
      i = tempvalue.num_value ;
      j = value.num_value ;
      tempnum = i % j ;
      value.num_value = tempnum ;
    } // else if

    oper = mtokenList[mindex].name ;
    tempvalue = value ;
  } // while
} // Parser::CAL_Rest_of_maybe_mult_exp()

void Parser::CAL_Unary_exp( Value & value ) {
  bool isarray = false ;
  string temp = "" ;
  string tempID = "" ;
  int index = 0 ;
  Value tempvalue ;
  string op = "" ;
  if ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
       mtokenList[mindex].name == "!" ) {
    temp = mtokenList[mindex].name ;
    CAL_Sign( value ) ;
    while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
            mtokenList[mindex].name == "!" ) {
      CAL_Sign( value ) ;
    } // while

    CAL_Signed_unary_exp( value, temp ) ; // 那麼多sign 可以幹嘛?????? 
  } // if
  else if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].type == CONSTANT || 
            mtokenList[mindex].name == "(" ) {
    CAL_Unsigned_unary_exp( value ) ;
  } // else if
  else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
    op = mtokenList[mindex].name ;
    mindex++ ;
    if ( mtokenList[mindex].type == IDENT ) {
      tempID = mtokenList[mindex].name ;
      tempvalue = IDvalue( tempID ) ;
      value = IDvalue( tempID ) ;
      mindex++ ;
      if ( mtokenList[mindex].name == "[" ) {
        isarray = true ;
        mindex++ ;
        CAL_Expression( value ) ;
        index = value.num_value ;
        if ( mtokenList[mindex].name == "]" ) {
          mindex++ ;

        } // if

        if ( tempvalue.type == INT || tempvalue.type == FLOAT ) {
          value.type = tempvalue.type ;
          value.num_value = tempvalue.num_array[index] ;
        } // if
        else if ( tempvalue.type == STRING ) {
          value.type = tempvalue.type ;
          value.str_value = tempvalue.str_array[index] ;
        } // else if
        else if ( tempvalue.type == CHAR ) {
          value.type = tempvalue.type ;
          value.char_value = tempvalue.char_array[index] ;
        } // else if
      } // if


      if ( op == "++" ) {
        value.num_value++ ;
        tempvalue.num_array[index]++ ;
      } // if
      else if ( op == "--" ) {
        value.num_value-- ;
        tempvalue.num_array[index]-- ;
      } // else if

      if ( isarray )
        Set_Variable_value( tempvalue, tempID ) ;
      else
        Set_Variable_value( value, tempID ) ;
    } // if

  } // else if
} // Parser::CAL_Unary_exp()

void Parser::CAL_Signed_unary_exp( Value & value, string sign ) {
  int index = 0 ;
  Value tempvalue ;
  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      misprint = false ;
      mindex++ ;
      if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
           mtokenList[mindex].name == "--" || 
           mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
           mtokenList[mindex].name == "!" ||
           mtokenList[mindex].type == CONSTANT || mtokenList[mindex].name == "(" ) {
        CAL_Actual_parameter_list( value ) ;
      } // if
      
      if ( mtokenList[mindex].name == ")" ) {
        misprint = true ;
        mindex++ ;
      } // if

    } // if
    else if ( mtokenList[mindex].name == "[" ) {
      tempvalue = IDvalue( mtokenList[mindex - 1].name ) ;
      mindex++ ;
      CAL_Expression( value ) ;
      index = value.num_value ;
      if ( mtokenList[mindex].name == "]" ) {
        mindex++ ;
      } // if
      
      if ( tempvalue.type == INT || tempvalue.type == FLOAT ) {
        value.type = tempvalue.type ;
        value.num_value = tempvalue.num_array[index] ;
      } // if
      else if ( tempvalue.type == STRING ) {
        value.type = tempvalue.type ;
        value.str_value = tempvalue.str_array[index] ;
      } // else if
      else if ( tempvalue.type == CHAR ) {
        value.type = tempvalue.type ;
        value.char_value = tempvalue.char_array[index] ;
      } // else if
      

    } // else if
    else {
      value = IDvalue( mtokenList[mindex - 1].name ) ; // 變數需要被assign過才會有值 
    } // else
  } // if
  else if ( mtokenList[mindex].type == CONSTANT ) {
    if ( mtokenList[mindex].name[0] == '"' ) {
      value.str_value = mtokenList[mindex].name ;
      value.type = STRING ;
    } // if
    else if ( mtokenList[mindex].name[0] == '\'' ) {
      value.char_value = mtokenList[mindex].name[1] ; // 還沒考慮反斜線 
      value.type = CHAR ;
    } // else if
    else if ( mtokenList[mindex].name == "true" || mtokenList[mindex].name == "false" ) {
      if ( mtokenList[mindex].name == "true" )
        value.bool_value = true ;
      else if ( mtokenList[mindex].name == "false" )
        value.bool_value = false ;
      value.type = BOOL ;
    } // else if
    else {
      value.num_value = atof( mtokenList[mindex].name.c_str() ) ;
      if ( Havedot( mtokenList[mindex].name ) )
        value.type = FLOAT ;
      else
        value.type = INT ;
    } // else

    mindex++ ;
  } // else if
  else if ( mtokenList[mindex].name == "(" ) {
    misprint = false ;
    mindex++ ;
    CAL_Expression( value ) ;
    if ( mtokenList[mindex].name == ")" ) {
      misprint = true ;
      mindex++ ;
    } // if

  } // else if

  if ( sign == "+" )
    ;
  else if ( sign == "-" )
    value.num_value = -value.num_value ;
  else if ( sign == "!" )
    value.bool_value = !value.bool_value ;

} // Parser::CAL_Signed_unary_exp()

void Parser::CAL_Unsigned_unary_exp( Value & value ) {
  bool isarray = false ;
  Value tempvalue ;
  string tempID = "" ;
  int index = 0 ;
  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      misprint = false ;
      mindex++ ;
      if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
           mtokenList[mindex].name == "--" || 
           mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
           mtokenList[mindex].name == "!" ||
           mtokenList[mindex].type == CONSTANT || mtokenList[mindex].name == "(" ) {
        CAL_Actual_parameter_list( value ) ;
      } // if
      
      if ( mtokenList[mindex].name == ")" ) {
        misprint = true ;
        mindex++ ;
      } // if
    } // if
    else if ( mtokenList[mindex].name == "[" ) {
      isarray = true ;
      tempvalue = IDvalue( mtokenList[mindex - 1].name ) ;
      tempID = mtokenList[mindex - 1].name ;
      mindex++ ;
      CAL_Expression( value ) ;
      index = value.num_value ;
      if ( mtokenList[mindex].name == "]" ) {
        mindex++ ;

      } // if

      if ( tempvalue.type == INT || tempvalue.type == FLOAT ) {
        value.type = tempvalue.type ;
        value.num_value = tempvalue.num_array[index] ;
      } // if
      else if ( tempvalue.type == STRING ) {
        value.type = tempvalue.type ;
        value.str_value = tempvalue.str_array[index] ;
      } // else if
      else if ( tempvalue.type == CHAR ) {
        value.type = tempvalue.type ;
        value.char_value = tempvalue.char_array[index] ;
      } // else if

      if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {

        if ( mtokenList[mindex].name == "++" ) {
          tempvalue.num_array[index]++ ;
        } // if
        else if ( mtokenList[mindex].name == "--" ) {
          tempvalue.num_array[index]-- ;
        } // else if

        if ( isarray )
          Set_Variable_value( tempvalue, tempID ) ;
        else
          Set_Variable_value( value, tempID ) ;

        mindex++ ;
      } // if
    } // else if
    else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
      value = IDvalue( mtokenList[mindex - 1].name ) ;
      tempvalue = value ;
      if ( mtokenList[mindex].name == "++" )
        value.num_value++ ;
      else if ( mtokenList[mindex].name == "--" )
        value.num_value-- ;
      Set_Variable_value( value, mtokenList[mindex - 1].name ) ;

      value = tempvalue ;
      mindex++ ;
    } // else if
    else {
      value = IDvalue( mtokenList[mindex-1].name ) ; // 變數需要被assign過才會有值 
    } // else
  } // if
  else if ( mtokenList[mindex].type == CONSTANT ) {
    if ( mtokenList[mindex].name[0] == '"' ) {
      value.str_value = mtokenList[mindex].name ;
      value.type = STRING ;
    } // if
    else if ( mtokenList[mindex].name[0] == '\'' ) {
      value.char_value = mtokenList[mindex].name[1] ; // 還沒考慮反斜線 
      value.type = CHAR ;
    } // else if
    else if ( mtokenList[mindex].name == "true" || mtokenList[mindex].name == "false" ) {
      if ( mtokenList[mindex].name == "true" )
        value.bool_value = true ;
      else if ( mtokenList[mindex].name == "false" )
        value.bool_value = false ;
      value.type = BOOL ;
    } // else if
    else {
      value.num_value = atof( mtokenList[mindex].name.c_str() ) ;
      if ( Havedot( mtokenList[mindex].name ) )
        value.type = FLOAT ;
      else
        value.type = INT ;
    } // else

    mindex++ ;
  } // else if
  else if ( mtokenList[mindex].name == "(" ) {
    misprint = false ;
    mindex++ ;
    CAL_Expression( value ) ;
    if ( mtokenList[mindex].name == ")" ) {
      misprint = true ;
      mindex++ ;
    } // if
  } // else if

} // Parser::CAL_Unsigned_unary_exp()

// --------------------------------------------------------------------------------------------------------

void Parser::Skip_Type_specifier() {

  if ( mtokenList[mindex].name == "int" || mtokenList[mindex].name == "char" || 
       mtokenList[mindex].name == "float" || 
       mtokenList[mindex].name == "string" || mtokenList[mindex].name == "bool" ) {
    mindex++ ;
  } // if

} // Parser::Skip_Type_specifier()

void Parser::Skip_Rest_of_declarators() {

  if ( mtokenList[mindex].name == "[" ) {
    
    mindex++ ; 
    if ( mtokenList[mindex].type == CONSTANT ) {
      mindex++ ;
      if ( mtokenList[mindex].name == "]" ) {
        mindex++ ;
      } // if

    } // if

  } // if

  while ( mtokenList[mindex].name == "," ) {

    mindex++ ;
    if ( mtokenList[mindex].type == IDENT ) {

      mindex++ ;
    } // if


    if ( mtokenList[mindex].name == "[" ) {
      mindex++ ;
      if ( mtokenList[mindex].type == CONSTANT ) {
        mindex++ ;
        if ( mtokenList[mindex].name == "]" ) {
          mindex++ ;
        } // if

      } // if
    } // if

  } // while
  
  if ( mtokenList[mindex].name == ";" ) {
    mindex++ ;
  } // if

} // Parser::Skip_Rest_of_declarators()

void Parser::Skip_Compound_statement() {

  if ( mtokenList[mindex].name == "{" ) {
    mindex++ ;

    while ( mtokenList[mindex].name != "}" ) {
      if ( mtokenList[mindex].name == "int" || mtokenList[mindex].name == "char" || 
           mtokenList[mindex].name == "float" || mtokenList[mindex].name == "string" || 
           mtokenList[mindex].name == "bool" ) {
        Skip_Declaration() ;
      } // if
      else {
        Skip_Statement() ;
      } // else

    } // while  有可能卡無窮 我不知道這樣寫可不可以
    
    if ( mtokenList[mindex].name == "}" ) {
      mindex++ ;
    } // if
  } // if

} // Parser::Skip_Compound_statement()

void Parser::Skip_Declaration() {

  Skip_Type_specifier() ;
  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    
    Skip_Rest_of_declarators() ;
  } // if

} // Parser::Skip_Declaration()

void Parser::Skip_Statement() {

  if ( mtokenList[mindex].name == ";" ) {
    mindex++ ;
  } // if
  else if ( mtokenList[mindex].name == "return" ) {

    mindex++ ;
    if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
         mtokenList[mindex].name == "--"  || mtokenList[mindex].name == "+" || 
         mtokenList[mindex].name == "-" || mtokenList[mindex].name == "!" 
         || mtokenList[mindex].type == CONSTANT || mtokenList[mindex].name == "(" )
      Skip_Expression() ; // 我不太確定條件要放啥 可能有問題
    if ( mtokenList[mindex].name == ";" ) {
      mindex++ ;
    } // if

  } // else if
  else if ( mtokenList[mindex].name == "if" ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      mindex++ ;
      Skip_Expression() ;
      if ( mtokenList[mindex].name == ")" ) {

        mindex++ ;
      } // if
    
      Skip_Statement() ;
      if ( mtokenList[mindex].name == "else" ) {
        mindex++ ;
        Skip_Statement() ;
      } // if
    } // if
  } // else if
  else if ( mtokenList[mindex].name == "while" ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {

      mindex++ ;
      Skip_Expression() ;
      if ( mtokenList[mindex].name == ")" ) {

        mindex++ ;
      } // if
      
      Skip_Statement() ;
    } // if
  } // else if
  else if ( mtokenList[mindex].name == "do" ) {
    mindex++ ;
    Skip_Statement() ;
    if ( mtokenList[mindex].name == "while" ) {
      mindex++ ;
      if ( mtokenList[mindex].name == "(" ) {
        mindex++ ;
        Skip_Expression() ;
        if ( mtokenList[mindex].name == ")" ) {
          mindex++ ;
          if ( mtokenList[mindex].name == ";" ) {
            mindex++ ;
          } // if
        } // if

      } // if

    } // if
  } // else if
  else if ( mtokenList[mindex].name == "{" ) {
    Skip_Compound_statement() ;
  } // else if
  else {
    Skip_Expression() ;
    if ( mtokenList[mindex].name == ";" ) {
      mindex++ ;
    } // if
  } // else
} // Parser::Skip_Statement()

void Parser::Skip_Expression() {

  Skip_Basic_expression() ;
  while ( mtokenList[mindex].name == "," ) {
    mindex++ ;
    Skip_Basic_expression() ;
  } // while
} // Parser::Skip_Expression()

void Parser::Skip_Basic_expression() {

  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    Skip_Rest_of_Identifier_started_basic_exp() ;
  } // if
  else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
    mindex++ ;
    if ( mtokenList[mindex].type == IDENT ) {

      mindex++ ;
      Skip_Rest_of_PPMM_Identifier_started_basic_exp() ;
    } // if
  } // else if
  else if ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-"  || 
            mtokenList[mindex].name == "!" ) {
    Skip_Sign() ;
    while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
            mtokenList[mindex].name == "!" ) {
      Skip_Sign() ;
    } // while
    
    Skip_Signed_unary_exp() ;
    Skip_Romce_and_romloe() ;

  } // else if
  else if ( mtokenList[mindex].type == CONSTANT ) {

    mindex++ ;
    Skip_Romce_and_romloe() ;
  } // else if
  else if ( mtokenList[mindex].name == "(" ) {
    mindex++ ;
    Skip_Expression() ;
    if ( mtokenList[mindex].name == ")" ) {
      mindex++ ;
    } // if

    Skip_Romce_and_romloe() ;
  } // else if
} // Parser::Skip_Basic_expression()

void Parser::Skip_Rest_of_Identifier_started_basic_exp() {
  if ( mtokenList[mindex].name == "[" ) {
    mindex++ ;
    Skip_Expression() ;
    if ( mtokenList[mindex].name == "]" ) {
      mindex++ ;
    } // if


    if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
      mindex++ ;

    } // if
    else if ( mtokenList[mindex].name == "+=" || mtokenList[mindex].name == "-=" || 
              mtokenList[mindex].name == "*=" || mtokenList[mindex].name == "/=" || 
              mtokenList[mindex].name == "%=" || mtokenList[mindex].name == "=" ) {
      Skip_Assignment_operator() ;
      Skip_Basic_expression() ;

    } // else if
    else {

      Skip_Romce_and_romloe() ;
    } // else
  } // if  陣列 

  else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {

    mindex++ ;

    Skip_Romce_and_romloe() ;
  } // else if
    
  else if ( mtokenList[mindex].name == "+=" || mtokenList[mindex].name == "-=" || 
            mtokenList[mindex].name == "*=" || mtokenList[mindex].name == "/=" || 
            mtokenList[mindex].name == "%=" || mtokenList[mindex].name == "=" ) {

    Skip_Assignment_operator() ;
    Skip_Basic_expression() ;

  } // else if

  else if ( mtokenList[mindex].name == "(" ) {
    mindex++ ;
    if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
         mtokenList[mindex].name == "--" || 
         mtokenList[mindex].name == "+" || mtokenList[mindex].name == "!" ||
         mtokenList[mindex].name == "-" || mtokenList[mindex].type == CONSTANT || 
         mtokenList[mindex].name == "(" ) {
      Skip_Actual_parameter_list() ;
    } // if
    
    if ( mtokenList[mindex].name == ")" ) {
      mindex++ ;
    } // if
    
    Skip_Romce_and_romloe() ;
  } // else if
  else {
    Skip_Romce_and_romloe() ;
  } // else
} // Parser::Skip_Rest_of_Identifier_started_basic_exp()

void Parser::Skip_Rest_of_PPMM_Identifier_started_basic_exp() {
  if ( mtokenList[mindex].name == "[" ) {
    mindex++ ;
    Skip_Expression() ;
    if ( mtokenList[mindex].name == "]" ) {
      mindex++ ;
    } // if

  } // if


  Skip_Romce_and_romloe() ;
} // Parser::Skip_Rest_of_PPMM_Identifier_started_basic_exp()

void Parser::Skip_Sign() {

  if ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || mtokenList[mindex].name == "!" ) {
    mindex++ ;
  } // if

} // Parser::Skip_Sign()

void Parser::Skip_Actual_parameter_list() {

  Skip_Basic_expression() ;
  while ( mtokenList[mindex].name == "," ) {
    mindex++ ;
    Skip_Basic_expression() ;
  } // while
} // Parser::Skip_Actual_parameter_list()

void Parser::Skip_Assignment_operator() {

  if ( mtokenList[mindex].name == "+=" || mtokenList[mindex].name == "-=" || 
       mtokenList[mindex].name == "*=" || 
       mtokenList[mindex].name == "/=" || mtokenList[mindex].name == "%=" || 
       mtokenList[mindex].name == "=" ) {
    mindex++ ;
  } // if

} // Parser::Skip_Assignment_operator()

void Parser::Skip_Romce_and_romloe() {

  Skip_Rest_of_maybe_logical_OR_exp() ;
  if ( mtokenList[mindex].name == "?" ) {
    mindex++ ;

    Skip_Basic_expression() ;
    if ( mtokenList[mindex].name == ":" ) {


      mindex++ ;
      Skip_Basic_expression() ;
    } // if


    // 還沒搞懂這要怎麼寫 
  } // if
} // Parser::Skip_Romce_and_romloe()

void Parser::Skip_Rest_of_maybe_logical_OR_exp() {
  Skip_Rest_of_maybe_logical_AND_exp() ;
  while ( mtokenList[mindex].name == "||" ) {
    mindex++ ;
    Skip_Maybe_logical_AND_exp() ;

  } // while
} // Parser::Skip_Rest_of_maybe_logical_OR_exp()

void Parser::Skip_Maybe_logical_AND_exp() {

  Skip_Maybe_bit_OR_exp() ;
  while ( mtokenList[mindex].name == "&&" ) {
    mindex++ ;
    Skip_Maybe_bit_OR_exp() ;

  } // while

} // Parser::Skip_Maybe_logical_AND_exp()

void Parser::Skip_Rest_of_maybe_logical_AND_exp() {

  Skip_Rest_of_maybe_bit_OR_exp() ;
  while ( mtokenList[mindex].name == "&&" ) {
    mindex++ ;
    Skip_Maybe_bit_OR_exp() ;

  } // while
} // Parser::Skip_Rest_of_maybe_logical_AND_exp()

void Parser::Skip_Maybe_bit_OR_exp() {

  Skip_Maybe_bit_ex_OR_exp() ;

  while ( mtokenList[mindex].name == "|" ) {
    mindex++ ;
    Skip_Maybe_bit_ex_OR_exp() ;

  } // while


} // Parser::Skip_Maybe_bit_OR_exp()

void Parser::Skip_Rest_of_maybe_bit_OR_exp() {

  Skip_Rest_of_maybe_bit_ex_OR_exp() ;

  while ( mtokenList[mindex].name == "|" ) {
    mindex++ ;
    Skip_Maybe_bit_ex_OR_exp() ;

  } // while

} // Parser::Skip_Rest_of_maybe_bit_OR_exp()

void Parser::Skip_Maybe_bit_ex_OR_exp() {

  Skip_Maybe_bit_AND_exp() ;

  while ( mtokenList[mindex].name == "^" ) {
    mindex++ ;
    Skip_Maybe_bit_AND_exp() ;

  } // while

} // Parser::Skip_Maybe_bit_ex_OR_exp()

void Parser::Skip_Rest_of_maybe_bit_ex_OR_exp() {

  Skip_Rest_of_maybe_bit_AND_exp() ;

  while ( mtokenList[mindex].name == "^" ) {
    mindex++ ;
    Skip_Maybe_bit_AND_exp() ;

  } // while
  
} // Parser::Skip_Rest_of_maybe_bit_ex_OR_exp()

void Parser::Skip_Maybe_bit_AND_exp() {

  Skip_Maybe_equality_exp() ;
  while ( mtokenList[mindex].name == "&" ) {
    mindex++ ;
    Skip_Maybe_equality_exp() ;
  } // while
  

} // Parser::Skip_Maybe_bit_AND_exp()

void Parser::Skip_Rest_of_maybe_bit_AND_exp() {

  Skip_Rest_of_maybe_equality_exp() ;

  while ( mtokenList[mindex].name == "&" ) {
    mindex++ ;
    Skip_Maybe_equality_exp() ;

  } // while
  

} // Parser::Skip_Rest_of_maybe_bit_AND_exp()

void Parser::Skip_Maybe_equality_exp() {

  Skip_Maybe_relational_exp() ;

  while ( mtokenList[mindex].name == "==" || mtokenList[mindex].name == "!=" ) {
    mindex++ ;
    Skip_Maybe_relational_exp() ;

  } // while
  

} // Parser::Skip_Maybe_equality_exp()

void Parser::Skip_Rest_of_maybe_equality_exp() {

  Skip_Rest_of_maybe_relational_exp() ;

  while ( mtokenList[mindex].name == "==" || mtokenList[mindex].name == "!=" ) {
    mindex++ ;
    Skip_Maybe_relational_exp() ;

  } // while

} // Parser::Skip_Rest_of_maybe_equality_exp()

void Parser::Skip_Maybe_relational_exp() {
  Skip_Maybe_shift_exp() ;

  while ( mtokenList[mindex].name == ">" || mtokenList[mindex].name == "<" || 
          mtokenList[mindex].name == ">=" || mtokenList[mindex].name == "<=" ) {
    mindex++ ;
    Skip_Maybe_shift_exp() ;

  } // while
  

} // Parser::Skip_Maybe_relational_exp()

void Parser::Skip_Rest_of_maybe_relational_exp() {

  Skip_Rest_of_maybe_shift_exp() ;
  while ( mtokenList[mindex].name == ">" || mtokenList[mindex].name == "<" || 
          mtokenList[mindex].name == ">=" || mtokenList[mindex].name == "<=" ) {
    mindex++ ;
    Skip_Maybe_shift_exp() ;

  } // while

} // Parser::Skip_Rest_of_maybe_relational_exp()

void Parser::Skip_Maybe_shift_exp() {
  Skip_Maybe_additive_exp() ;
  while ( mtokenList[mindex].name == "<<" || mtokenList[mindex].name == ">>" ) {
    mindex++ ;
    Skip_Maybe_additive_exp() ;

  } // while
} // Parser::Skip_Maybe_shift_exp()

void Parser::Skip_Rest_of_maybe_shift_exp() {

  Skip_Rest_of_maybe_additive_exp() ;

  while ( mtokenList[mindex].name == "<<" || mtokenList[mindex].name == ">>" ) {
    mindex++ ;
    Skip_Maybe_additive_exp() ;
  } // while
} // Parser::Skip_Rest_of_maybe_shift_exp() 

void Parser::Skip_Maybe_additive_exp() {

  Skip_Maybe_mult_exp() ;

  while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" ) {
    mindex++ ;
    Skip_Maybe_mult_exp() ;

  } // while
} // Parser::Skip_Maybe_additive_exp()

void Parser::Skip_Rest_of_maybe_additive_exp() {
  Skip_Rest_of_maybe_mult_exp() ;

  while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" ) {
    mindex++ ;
    Skip_Maybe_mult_exp() ;

  } // while
} // Parser::Skip_Rest_of_maybe_additive_exp()

void Parser::Skip_Maybe_mult_exp() {
  Skip_Unary_exp() ;
  Skip_Rest_of_maybe_mult_exp() ;
} // Parser::Skip_Maybe_mult_exp()

void Parser::Skip_Rest_of_maybe_mult_exp() {

  while ( mtokenList[mindex].name == "*" || mtokenList[mindex].name == "/" || 
          mtokenList[mindex].name == "%" ) {
    mindex++ ;
    Skip_Unary_exp() ;
  } // while
} // Parser::Skip_Rest_of_maybe_mult_exp()

void Parser::Skip_Unary_exp() {

  if ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
       mtokenList[mindex].name == "!" ) {

    Skip_Sign() ;
    while ( mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
            mtokenList[mindex].name == "!" ) {
      Skip_Sign() ;
    } // while

    Skip_Signed_unary_exp() ; // 那麼多sign 可以幹嘛?????? 
  } // if
  else if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].type == CONSTANT || 
            mtokenList[mindex].name == "(" ) {
    Skip_Unsigned_unary_exp() ;
  } // else if
  else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
    mindex++ ;
    if ( mtokenList[mindex].type == IDENT ) {
      mindex++ ;
      if ( mtokenList[mindex].name == "[" ) {
        mindex++ ;
        Skip_Expression() ;
        if ( mtokenList[mindex].name == "]" ) {
          mindex++ ;

        } // if

      } // if
    } // if

  } // else if
} // Parser::Skip_Unary_exp()

void Parser::Skip_Signed_unary_exp() {
  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      mindex++ ;
      if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
           mtokenList[mindex].name == "--" || 
           mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
           mtokenList[mindex].name == "!" ||
           mtokenList[mindex].type == CONSTANT || mtokenList[mindex].name == "(" ) {
        Skip_Actual_parameter_list() ;
      } // if
      
      if ( mtokenList[mindex].name == ")" ) {
        mindex++ ;
      } // if

    } // if
    else if ( mtokenList[mindex].name == "[" ) {

      mindex++ ;
      Skip_Expression() ;

      if ( mtokenList[mindex].name == "]" ) {
        mindex++ ;
      } // if

      

    } // else if
  } // if
  else if ( mtokenList[mindex].type == CONSTANT ) {

    mindex++ ;
  } // else if
  else if ( mtokenList[mindex].name == "(" ) {
    mindex++ ;
    Skip_Expression() ;
    if ( mtokenList[mindex].name == ")" ) {
      mindex++ ;
    } // if

  } // else if


} // Parser::Skip_Signed_unary_exp()

void Parser::Skip_Unsigned_unary_exp() {
  if ( mtokenList[mindex].type == IDENT ) {
    mindex++ ;
    if ( mtokenList[mindex].name == "(" ) {
      mindex++ ;
      if ( mtokenList[mindex].type == IDENT || mtokenList[mindex].name == "++" || 
           mtokenList[mindex].name == "--" || 
           mtokenList[mindex].name == "+" || mtokenList[mindex].name == "-" || 
           mtokenList[mindex].name == "!" ||
           mtokenList[mindex].type == CONSTANT || mtokenList[mindex].name == "(" ) {
        Skip_Actual_parameter_list() ;
      } // if
      
      if ( mtokenList[mindex].name == ")" ) {

        mindex++ ;
      } // if
    } // if
    else if ( mtokenList[mindex].name == "[" ) {
      mindex++ ;
      Skip_Expression() ;
      if ( mtokenList[mindex].name == "]" ) {
        mindex++ ;

      } // if


      if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {

        mindex++ ;
      } // if
    } // else if
    else if ( mtokenList[mindex].name == "++" || mtokenList[mindex].name == "--" ) {
      mindex++ ;
    } // else if
  } // if
  else if ( mtokenList[mindex].type == CONSTANT ) {

    mindex++ ;
  } // else if
  else if ( mtokenList[mindex].name == "(" ) {
    mindex++ ;
    Skip_Expression() ;
    if ( mtokenList[mindex].name == ")" ) {
      mindex++ ;
    } // if
  } // else if

} // Parser::Skip_Unsigned_unary_exp()

// ---------------------------------------------------------------------------------------------
bool Parser::Havedot( string num ) {
  for ( int i = 0 ; i < num.size() ; i++ ) {
    if ( num[i] == '.' )
      return true ;
  } // for
  
  return false ;
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
  misprint = true ;
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



