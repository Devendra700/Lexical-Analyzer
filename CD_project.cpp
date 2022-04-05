#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
unordered_set<string> identifiers;
// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
		ch == '%' || ch == '&' || ch == '|' || ch == '~' ||
		ch == '^' || ch=='!' || ch=='"')
		return (true);
	return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool Operator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=' || ch == '%' || ch == '&' ||
		ch == '|' || ch == '~' || ch == '^' || ch=='!')
		return (true);
	return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
		return (false);
	return (true);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||  !strcmp(str,"for") ||
		!strcmp(str, "continue") || !strcmp(str, "int")
		|| !strcmp(str, "double") || !strcmp(str, "float")
		|| !strcmp(str, "return") || !strcmp(str, "char")
		|| !strcmp(str, "case") || !strcmp(str, "char")
		|| !strcmp(str, "sizeof") || !strcmp(str, "long")
		|| !strcmp(str, "short") || !strcmp(str, "typedef")
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned")
		|| !strcmp(str, "void") || !strcmp(str, "static")
		|| !strcmp(str, "struct") || !strcmp(str, "goto")
        || !strcmp(str, "printf") || !strcmp(str, "scanf"))
		return (true);
	return (false);
}

bool isDefinition(char* str)
{
	if (!strcmp(str, "double") || !strcmp(str, "int")
		|| !strcmp(str, "float") || !strcmp(str, "char"))
		return (true);
	return (false);
}


bool isOperator(char* str)
{
	if (!strcmp(str, "++") || !strcmp(str, "--") ||
		!strcmp(str, "+") || !strcmp(str, "-") ||
		!strcmp(str, "*") ||
		!strcmp(str, "/") || !strcmp(str, "%")
		|| !strcmp(str, "<") || !strcmp(str, "<=")
		|| !strcmp(str, "=") || !strcmp(str, ">")
		|| !strcmp(str, ">=") || !strcmp(str, "==")
		|| !strcmp(str, "!=") || !strcmp(str, "&&")
		|| !strcmp(str, "||") || !strcmp(str, "!")
		|| !strcmp(str, "&") || !strcmp(str, "|")
		|| !strcmp(str, "<<") || !strcmp(str, ">>")
		|| !strcmp(str, "~") || !strcmp(str, "^")
        || !strcmp(str, "+=") || !strcmp(str, "-=")
        || !strcmp(str, "*=") || !strcmp(str, "/=")
        || !strcmp(str, "%="))
		return (true);
	return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}

int isConstant(char *str)
{
 int len=strlen(str);
 if(isInteger(str))
        return(1);
 else if(isRealNumber(str))
     return(1);
  else
  {
   int a=str[0],b=str[len-1];
   if(a==39)
   {
    if(len!=3)
         return(-1);
    if(a==b)
         return(1);
    else
         return(-1);
   }
  }
 return(0);
}
// Extracts the SUBSTRING.
char* subString(char *str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
				sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

char *remove_white_spaces(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
          str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}

char* substr(const char *src, int m, int n)
{
    int len = n - m;
    char *dest = (char*)malloc(sizeof(char) * (len + 1));

    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    *dest = '\0';
    return dest - len;
}

char *remove_white_spaces_start(char *str)
{
	int i = 0,j=strlen(str);
	while (str[i]!='\0')
	{
		if (str[i] != ' ')
          break;
		i++;
	}
	char *str1=substr(str,i,j);
	return str1;
}

char *remove_line_punctuation(char *token)
{
 int i,j=strlen(token);
 if(token[j-1]==';')
        token[j-1]='\0';
 return(token);
}

char *remove_newline(char *str)
{
 int i=strlen(str);
 if(str[i-1]=='\n')
        str[i-1]='\0';
 return(str);
}

// Parsing the input STRING.
void parse(char *str)
{
	int left = 0, right = 0;
	int len = strlen(str);

	while (right <= len && left <= right) {
		if (isDelimiter(str[right]) == false)
			right++;

		else if (isDelimiter(str[right]) == true && left == right) {
	      if(str[left]=='"')
          {
           right++;
           while(right<=len && str[right]!='"')
                 right++;
           right++;
           char* subStr = subString(str, left, right - 1);
           printf("'%s' is a string\n",subStr);
            left=right;
           }
		  else if(str[right]==' ')
          {
           right++;
			left = right;
			continue;
          }
          /*********************** for {} braces*********************/
          /*else if(str[right]=='{'||str[right]=='}')
            {
             right++;
             left=right;
             continue;
            }*/

          else
          {
           right++;
           while(Operator(str[right]))
            right++;
           char* subStr = subString(str, left, right - 1);
           if(isOperator(subStr))
                printf("'%s' IS A OPERATOR\n",subStr);
           else
                    printf("'%s' IS A PUNCTUATION\n",subStr);
           left=right;
           //right++;
          }
		}
		else if (isDelimiter(str[right]) == true && left != right
				|| (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);

			if (isKeyword(subStr) == true)
            {
				printf("'%s' IS A KEYWORD\n", subStr);
				if(isDefinition(subStr))
                {
                 int p=right+1;
                 /*************************************************/

                 /*************************************************/
                }
            }

		    else if(isConstant(subStr)==1)
                        printf("%s IS A CONSTANT\n",subStr);
            else if(isConstant(subStr)==-1)
            {
             printf("There is an Error in this line\n");
             return;
            }
            else if(isOperator(subStr))
                printf("'%s' is a operator\n",subStr);

            else if (identifiers.find(subStr)!=identifiers.end()
					&& isDelimiter(str[right - 1]) == false)
				printf("'%s' IS A VALID IDENTIFIER\n", subStr);
		    else
                        printf("'%s' is an invalid identifiers please define this identifier first in the proram before use\n",subStr);
			left = right;
		}
	}
	return;
}
// DRIVER FUNCTION
int main()
{
	// maximum length of string is 100 here
	 FILE* filePointer;
     int bufferLength = 255;
     //char buffer[bufferLength];
     char buffer1[bufferLength];
     filePointer = fopen("file1.txt", "r");
     while(fgets(buffer1, bufferLength, filePointer)) {
            //char *buffer2=remove_white_spaces_start(buffer1);
        //char *buffer=remove_newline(buffer1);
        char *buffer=buffer1;
        //if(buffer[strlen(buffer)-1]=='\n')
        //{
         char str[255];
         int i=0;
         for(i=0;i<strlen(buffer)-1;i++)
         {
          if(buffer[i]!=' ')
                break;
         }
         int index=0;
         for(int start1=i;start1<strlen(buffer)-1;start1++)
              str[index++]=buffer[start1];
         str[index]='\0';
         //cout<<"This is the str"<<endl;
         //cout<<str<<endl;
         string s1;
         for(i=0;str[i]!='\0';i++)
             s1.push_back(str[i]);
         int is_int=0,is_float=0,is_char=0,is_double=0;
         /**********************************findin the int keyword in the buffer line that is scan from the file **********************/
         string s2="int ";
         if (s1.find(s2) != std::string::npos)
         {
          size_t found = s1.find(s2);
          int p=found+3,q=0;
          char i_stream[255];
          is_int=1;
          while(str[p]!='\0')
          {
           i_stream[q++]=str[p];
           p++;
          }
          i_stream[q]='\0';
          //printf("i_stream is %s\n",i_stream);
           char* token = strtok(i_stream, ",");
           while (token != NULL) {
             token=remove_white_spaces(token);
             token=remove_line_punctuation(token);
             //printf("This is a token %s\n", token);
             string s3,s4="=";
             for(int k=0;k<strlen(token);k++)
                 s3.push_back(token[k]);
             if (s3.find(s4) != std::string::npos)
             {
               size_t found = s3.find(s4);
                string s5;
                char subStr[255];
                int p=0;
                for(int i=0;i<found;i++)
                {
                     s5.push_back(token[i]);
                     subStr[p++]=token[i];
                }
                subStr[p]='\0';
                 /*****************************  validation of identifier***********/
                 if (validIdentifier(subStr) == true)
                    identifiers.insert(s5);
                 else
                        printf("There is an invalid identifier %s in this line\n",subStr);
                 /*****************************/

                 /*******************************check for array ******************/
                 string s8="[";
                  if(validIdentifier(subStr)==true && s5.find(s8) != std::string::npos)
                  {
                   size_t found1 = s5.find(s8);
                   string s7;
                   for(int i=0;i<found1;i++)
                    s7.push_back(s5[i]);
                   identifiers.insert(s7);
                  }
                 /*****************************************************************/
                //cout<<s5<<endl;
             }
             else
             {
              char subStr[255];
              int i=0;
              for(i=0;s3[i]!='\0';i++)
                    subStr[i]=s3[i];
              subStr[i]='\0';
              //printf("there is an identifeir %s\n",subStr);
              if (validIdentifier(subStr) == true)
                    identifiers.insert(s3);
              else
                 printf("There is an invalid identifier %s in this line\n",subStr);
              string s8="[";
                  if(validIdentifier(subStr)==true && s3.find(s8) != std::string::npos)
                  {
                   size_t found1 = s3.find(s8);
                   string s7;
                   for(int i=0;i<found1;i++)
                    s7.push_back(s3[i]);
                   identifiers.insert(s7);
                  }
              //cout<<s3<<endl;
             }
            token = strtok(NULL, ",");
           }
         }
         /************************int section  is end here ***********************/
         /***************************float section start *************************/
         s2="float ";
         if (s1.find(s2) != std::string::npos && is_int==0)
         {
          size_t found = s1.find(s2);
          int p=found+5,q=0;
          char i_stream[255];
          is_float=1;
          while(str[p]!='\0')
          {
           i_stream[q++]=str[p];
           p++;
          }
          i_stream[q]='\0';
          //printf("i_stream is %s\n",i_stream);
           char* token = strtok(i_stream, ",");
           while (token != NULL) {
             token=remove_white_spaces(token);
             token=remove_line_punctuation(token);
             //printf("This is a token %s\n", token);
             string s3,s4="=";
             for(int k=0;k<strlen(token);k++)
                 s3.push_back(token[k]);
             if (s3.find(s4) != std::string::npos)
             {
               size_t found = s3.find(s4);
                string s5;
                char subStr[255];
                int p=0;
                for(int i=0;i<found;i++)
                {
                     s5.push_back(token[i]);
                     subStr[p++]=token[i];
                }
                subStr[p]='\0';
                 /*****************************  validation of identifier***********/
                 if (validIdentifier(subStr) == true)
                    identifiers.insert(s5);
                 else
                        printf("There is an invalid identifier %s in this line\n",subStr);
                 /*****************************/
                //cout<<s5<<endl;
             }
             else
             {
              char subStr[255];
              int i=0;
              for(i=0;s3[i]!='\0';i++)
                    subStr[i]=s3[i];
              subStr[i]='\0';
              //printf("there is an identifeir %s\n",subStr);
              if (validIdentifier(subStr) == true)
                    identifiers.insert(s3);
              else
                 printf("There is an invalid identifier %s in this line\n",subStr);
              //cout<<s3<<endl;
             }
            token = strtok(NULL, ",");
           }
         }
         /**************************** float section end here **********************/
         /*******************************double section is start here **************/
         s2="double ";
         if (s1.find(s2) != std::string::npos && is_int==0 && is_float==0)
         {
          size_t found = s1.find(s2);
          int p=found+6,q=0;
          char i_stream[255];
          is_double=1;
          while(str[p]!='\0')
          {
           i_stream[q++]=str[p];
           p++;
          }
          i_stream[q]='\0';
          //printf("i_stream is %s\n",i_stream);
           char* token = strtok(i_stream, ",");
           while (token != NULL) {
             token=remove_white_spaces(token);
             token=remove_line_punctuation(token);
             //printf("This is a token %s\n", token);
             string s3,s4="=";
             for(int k=0;k<strlen(token);k++)
                 s3.push_back(token[k]);
             if (s3.find(s4) != std::string::npos)
             {
               size_t found = s3.find(s4);
                string s5;
                char subStr[255];
                int p=0;
                for(int i=0;i<found;i++)
                {
                     s5.push_back(token[i]);
                     subStr[p++]=token[i];
                }
                subStr[p]='\0';
                 /*****************************  validation of identifier***********/
                 if (validIdentifier(subStr) == true)
                    identifiers.insert(s5);
                 else
                        printf("There is an invalid identifier %s in this line\n",subStr);
                 /*****************************/
                //cout<<s5<<endl;
             }
             else
             {
              char subStr[255];
              int i=0;
              for(i=0;s3[i]!='\0';i++)
                    subStr[i]=s3[i];
              subStr[i]='\0';
              //printf("there is an identifeir %s\n",subStr);
              if (validIdentifier(subStr) == true)
                    identifiers.insert(s3);
              else
                 printf("There is an invalid identifier %s in this line\n",subStr);
              //cout<<s3<<endl;
             }
            token = strtok(NULL, ",");
           }
         }
         /******************************double section is end here *****************/
         /****************************char section is start here********************/
         s2="char ";
         if (s1.find(s2) != std::string::npos && is_int==0 && is_float==0 && is_double==0)
         {
          size_t found = s1.find(s2);
          int p=found+4,q=0;
          char i_stream[255];
          is_int=1;
          while(str[p]!='\0')
          {
           i_stream[q++]=str[p];
           p++;
          }
          i_stream[q]='\0';
          //printf("i_stream is %s\n",i_stream);
           char* token = strtok(i_stream, ",");
           while (token != NULL) {
             token=remove_white_spaces(token);
             token=remove_line_punctuation(token);
             //printf("This is a token %s\n", token);
             string s3,s4="=";
             for(int k=0;k<strlen(token);k++)
                 s3.push_back(token[k]);
             if (s3.find(s4) != std::string::npos)
             {
               size_t found = s3.find(s4);
                string s5;
                char subStr[255];
                int p=0;
                for(int i=0;i<found;i++)
                {
                     s5.push_back(token[i]);
                     subStr[p++]=token[i];
                }
                subStr[p]='\0';
                 /*****************************  validation of identifier***********/
                 if (validIdentifier(subStr) == true)
                    identifiers.insert(s5);
                 else
                        printf("There is an invalid identifier %s in this line\n",subStr);
                 /*****************************/
                //cout<<s5<<endl;
             }
             else
             {
              char subStr[255];
              int i=0;
              for(i=0;s3[i]!='\0';i++)
                    subStr[i]=s3[i];
              subStr[i]='\0';
              //printf("there is an identifeir %s\n",subStr);
              if (validIdentifier(subStr) == true)
                    identifiers.insert(s3);
              else
                 printf("There is an invalid identifier %s in this line\n",subStr);
              //cout<<s3<<endl;
             }
            token = strtok(NULL, ",");
           }
         }
         /**************************** char section is end here *********************/
        /*******************************parsing line by line ***********************/
        parse(buffer);
     }
     //printf("symbols in symbol table\n");
     //for(string s:identifiers)
       // cout<<s<<endl;
	fclose(filePointer);
}

