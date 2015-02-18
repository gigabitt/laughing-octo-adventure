

#include <stdio.h>
// needed for string library
#include <string.h>
// needed for memory allocation
#include <stdlib.h>


int parse_command(char* line, char** cmd1, char** cmd2, char* infile, char* outfile);
void initial_parse(char * s);

int main(int argc, char *argv[])
{
    printf("The value of argc (number of command line arguments) is %d\n", argc);

    
    //use while loop here so that the user is prompted if they don't enter anything in the command line
    
    if (argc == 2){
        initial_parse(argv[1]);
    }
    
    return 0;
}
/*-----------------------initial_parse-------------------------------
 |  Function initial_parse
 |
 |  Purpose:  breaks arguments entered by user into arrays
 |
 |  Parameters:
 |	   argument (IN) - char * s: user's argument
 |
 |  Returns:
 |
 *-------------------------------------------------------------------*/

void initial_parse(char * s){
    char * second;
    second = NULL;
    char * first;
    
    
    // find the first | in the string s if any
    first = s;
    while ( *s != '\0'){
        if ( s[0] == '|' ){
            s[0] = '\0';
            second = s + 1;
            break;
        }
        s++;
    }
    
    // if there is a pipe
    if ( second != NULL ) {
        
        // making copy of first and second
        // store them in an array of c-style strings
        char * command[2];
        command[0] = malloc( ( strlen(first)+1 )*sizeof(char) );
        
        // using loop to copy
        int i=0;
        while ( (command[0][i]=first[i]) )
            i++;
        
        command[1] = malloc( ( strlen(second)+1 )*sizeof(char) );
        // use library function to copy
        strcpy (command[1], second);
    
        

        
        char * cmd_1[25] = {'\0'};
        
        
        //iterate through command[0]
        
        for(int i = 0; i < strlen(command[0]); i++){
            cmd_1[i] = malloc( (strlen (first)+1 )*sizeof(char));
        }
        
        
        
        int k = 0;
        int l = 0;
        int m = 0;
        int arr_len = 0;
        
        while(command[0][m] != '\0'){
            if(command[0][m] == ' ' ){
                if(command[0][m+1] == '\0'){
                    cmd_1[l+1] = '\0';
                    break;
                }
                if(k == 0){
                    m++;
                }
                else{
                    cmd_1[l][k] = '\0';
                    m++;
                    l++;
                    k = 0;
                }
            }

            else if(command[0][m] == '>'){
                if(command[0][m+1] == '>'){
                    cmd_1[l][k] = command[0][m];
                    cmd_1[l][k+1] = command[0][m+1];
                    m += 2;
                    k += 2;
                    while(command[0][m]  == ' '){
                        m++;
                    }
                    if(command[0][m+1] == '\0'){
                        cmd_1[l+1] = '\0';
                    }
                }
                else{
                    cmd_1[l][k] = command[0][m];
                    m++;
                    k++;
                    while(command[0][m] == ' '){
                        m++;
                    }
                    if(command[0][m+1] == '\0'){
                        cmd_1[l+1] = '\0';
                    }
                }
            }
            else if(command[0][m] == '<'){
                cmd_1[l][k] = command[0][m];
                m++;
                k++;
                while(command[0][m] == ' '){
                    m++;
                }
                if(command[0][m+1] == '\0'){
                    cmd_1[l+1] = '\0';
                }
            }
            else{
                cmd_1[l][k] = command[0][m];
                if(command[0][m+1] == '\0'){
                    cmd_1[l+1] = '\0';
                }
                k++;
                m++;

            }
            
        }
        arr_len = l + 1;
        
        char * cmd1[arr_len + 1];
        for(int i = 0; i < arr_len; i++){
            cmd1[i] = cmd_1[i];
        }
        cmd1[arr_len ] = '\0';
        
        for(i=0; i < arr_len + 1; i++){
            printf("cmd1[%d] %s \n", i, cmd1[i]);
        }

        
        for(int i = 0; i < strlen(command[0]); i++){
            free(cmd_1[i]);
        }
        
        
        
        
        
        
        
        
        
        
        
        
        char * cmd_2[25] = {'\0'};
        
        
        //iterate through command[0]
        
        for(int i = 0; i < strlen(command[1]); i++){
            cmd_2[i] = malloc( (strlen (second)+1 )*sizeof(char));
        }
        
        
        
        k = 0;
        l = 0;
        m = 0;
        int arr_len2 = 0;
        
        while(command[1][m] != '\0'){
            if(command[1][m] == ' ' ){
                if(command[1][m+1] == '\0'){
                    cmd_2[l+1] = '\0';
                    break;
                }
                if(k == 0){
                    m++;
                }
                else{
                    cmd_2[l][k] = '\0';
                    m++;
                    l++;
                    k = 0;
                }
            }
            
            else if(command[1][m] == '>'){
                if(command[1][m+1] == '>'){
                    cmd_2[l][k] = command[1][m];
                    cmd_2[l][k+1] = command[1][m+1];
                    m += 2;
                    k += 2;
                    while(command[1][m]  == ' '){
                        m++;
                    }
                    if(command[1][m+1] == '\0'){
                        cmd_2[l+1] = '\0';
                    }
                }
                else{
                    cmd_2[l][k] = command[1][m];
                    m++;
                    k++;
                    while(command[1][m] == ' '){
                        m++;
                    }
                    if(command[1][m+1] == '\0'){
                        cmd_2[l+1] = '\0';
                    }
                }
            }
            else if(command[1][m] == '<'){
                cmd_2[l][k] = command[1][m];
                m++;
                k++;
                while(command[1][m] == ' '){
                    m++;
                }
                if(command[1][m+1] == '\0'){
                    cmd_2[l+1] = '\0';
                }
            }
            else{
                cmd_2[l][k] = command[1][m];
                if(command[1][m+1] == '\0'){
                    cmd_2[l+1] = '\0';
                }
                k++;
                m++;
                
            }
            
        }
        arr_len2 = l + 1;
        
        char * cmd2[arr_len + 1];
        for(int i = 0; i < arr_len; i++){
            cmd2[i] = cmd_2[i];
        }
        cmd2[arr_len ] = '\0';
        
        for(i=0; i < arr_len2 + 1; i++){
            printf("cmd2[%d] %s \n", i, cmd2[i]);
        }
        
        
        for(int i = 0; i < strlen(command[1]); i++){
            free(cmd_2[i]);
        }
        
        
        
        // show array
        for (i=0; i < 2; i++)
            printf("command[%d] = %s\n", i, command[i]);
        
        // free space
        for (i=0; i < 2; i++)
            free( command[i] );
        
    } else {
        
        // making copy of first and second
        // store them in an array of c-style strings
        char * command[2];
        command[0] = malloc( ( strlen(first)+1 )*sizeof(char) );
        
        // using loop to copy
        int i=0;
        while ( (command[0][i]=first[i]) )
            i++;

        char * cmd_1[25] = {'\0'};
        
        
        //iterate through command[0]
        
        for(int i = 0; i < strlen(command[0]); i++){
            cmd_1[i] = malloc( (strlen (first)+1 )*sizeof(char));
        }
        
        
        
        int k = 0;
        int l = 0;
        int m = 0;
        int arr_len = 0;
        
        while(command[0][m] != '\0'){
            if(command[0][m] == ' ' ){
                if(command[0][m+1] == '\0'){
                    cmd_1[l+1] = '\0';
                    break;
                }
                if(k == 0){
                    m++;
                }
                else{
                    cmd_1[l][k] = '\0';
                    m++;
                    l++;
                    k = 0;
                }
            }
            
            else if(command[0][m] == '>'){
                if(command[0][m+1] == '>'){
                    cmd_1[l][k] = command[0][m];
                    cmd_1[l][k+1] = command[0][m+1];
                    m += 2;
                    k += 2;
                    while(command[0][m]  == ' '){
                        m++;
                    }
                    if(command[0][m+1] == '\0'){
                        cmd_1[l+1] = '\0';
                    }
                }
                else{
                    cmd_1[l][k] = command[0][m];
                    m++;
                    k++;
                    while(command[0][m] == ' '){
                        m++;
                    }
                    if(command[0][m+1] == '\0'){
                        cmd_1[l+1] = '\0';
                    }
                }
            }
            else if(command[0][m] == '<'){
                cmd_1[l][k] = command[0][m];
                m++;
                k++;
                while(command[0][m] == ' '){
                    m++;
                }
                if(command[0][m+1] == '\0'){
                    cmd_1[l+1] = '\0';
                }
            }
            else{
                cmd_1[l][k] = command[0][m];
                if(command[0][m+1] == '\0'){
                    cmd_1[l+1] = '\0';
                }
                k++;
                m++;
                
            }
            
        }
        arr_len = l + 1;
        
        char * cmd1[arr_len + 1];
        for(int i = 0; i < arr_len; i++){
            cmd1[i] = cmd_1[i];
        }
        cmd1[arr_len ] = '\0';
        
        for(i=0; i < arr_len + 1; i++){
            printf("cmd1[%d] %s \n", i, cmd1[i]);
        }
        
        
        for(int i = 0; i < strlen(command[0]); i++){
            free(cmd_1[i]);
        }
    }
    
    
}


/*-----------------------parse_command-------------------------------
 |  Function parse_command
 |
 |  Purpose:  Parse commands entered by the user and display what type
 |              of command the user entered.
 |
 |  Parameters:
 |	   argument (IN) - C-style strings: line, infile, outfile
 |                     Arrays of C-style strings: cmd1, cmd2.
 |
 |  Returns:  an integer 0-9 that specifies what type of argument was
 |            entered.
 |
 *-------------------------------------------------------------------*/

//int parse_command(char* line, char** cmd1, char** cmd2, char* infile, char* outfile){
    
    
//}
