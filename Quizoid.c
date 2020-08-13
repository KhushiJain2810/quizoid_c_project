#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

//during login...the 'signup_details' will be copied to these arrays
char array_name[20][50];
char array_password[20][50];

void gotoxy(int, int);
void _welcomepage();
int _loginsignupmenu();
void _signup();
void _login();
void _mainpage();
void _newgame();
void _rules();
void _highscore();
void _easy_quizoid();
void _hard_quizoid();
void _quit_page();
void _quit_opt();

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void _welcomepage()
{

    printf("\n\t\t                         :::::::::::::::::::::::::::::::::::::");
    printf("\n\t\t                         ::                                 ::");
    printf("\n\t\t                         ::     ***********************     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     *      WELCOME TO     *     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     *       QUIZOID       *     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     ***********************     ::");
    printf("\n\t\t                         ::                                 ::");
    printf("\n\t\t                         :::::::::::::::::::::::::::::::::::::\n\n");
    gotoxy(41,13);
    printf("Press Any Key To Continue: ");
    _getch();
    system("cls");
}
int _loginsignupmenu()
{
    system("cls");
    int choice;
    gotoxy(35, 2);
    printf("Enter Your Choice:");
    gotoxy(35, 4);
    printf("1. New User? Signup");
    gotoxy(35, 6);
    printf("2. Already have an account? Login");
    gotoxy(35, 8);
    printf("3. Exit");
    gotoxy(35, 10);
    printf(">  ");
    fflush(stdin);
    scanf("%d", &choice);
    return choice;
}

void _signup()
{
    FILE *fp1;
    fp1 = fopen("signup_details.txt", "a");
    if(!fp1)
    {
        printf("file 'signup_details.txt' not found\n");
        exit(0);
    }
    char signup_username[30], signup_password[30];
    system("cls");
    gotoxy(35, 2);
    printf("Enter Signup Details\n");
    //enter signup details
    gotoxy(35, 4);
    printf("Enter Username(There should be no space in username):  ");
    fflush(stdin);
    gets(signup_username);
    gotoxy(35, 6);
    printf("Enter Password:  ");
    fflush(stdin);
    gets(signup_password);
    //append details of new user to the 'signup_details' file
    fprintf(fp1, "%s %s\n", signup_username, signup_password);
    gotoxy(35, 8);
    printf("Signup Successful\n");
    //return to main() which will direct to login()
    fclose(fp1);
}

void _login()
{
    char login_username[30], login_password[30];
    FILE *fp1;
    fp1 = fopen("signup_details.txt", "r"); //open in read mode
    if(!fp1)
    {
        printf("file 'signup_details.txt' not found\n");
        exit(0);
    }
    //copy 'signup_details' to array_name and array_password
    int i = 0;
    while(!feof(fp1))
    {
        fscanf(fp1, "%s %s",array_name[i], array_password[i]);
        i++;
    }
    login:  //goto label... if no account matches then show 'Account does not exist' and ask the  user to enter login details again
    //enter login details
    system("cls");
    gotoxy(35, 2);
    printf("Enter Login Details\n");
    gotoxy(35, 4);
    printf("Enter Username:  ");
    fflush(stdin);
    gets(login_username);
    gotoxy(35, 6);
    printf("Enter Password:  ");
    fflush(stdin);
    gets(login_password);
    //check if login details match with existing accounts
    i = 0;
    int flag = 0;
    while(array_name[i][0] != NULL)
    {
        if( strcmp(array_name[i], login_username) == 0  &&  strcmp(array_password[i], login_password) == 0 )
        {
            printf("Login successful\n");
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0)   //if none account matches then ask the  user to enter login details again
    {
        gotoxy(35, 8);
        printf("Account does not exist\n");
        gotoxy(35, 9);
        printf("Press any key to enter login details again: ");
        _getch();
        goto login;
    }
    else
    {
        _mainpage();    //begin the quiz
    }
    fclose(fp1);
}
void _mainpage()
{
    system("cls");
    int choice;
    mainpage:  //goto label
    gotoxy(35, 2);
    printf("1. New game\n");
    gotoxy(35, 4);
    printf("2. Instructions\n");
    gotoxy(35, 6);
    printf("3. Highscore\n");
    gotoxy(35, 8);
    printf("4. Exit\n");
    gotoxy(35, 10);
    printf("Enter choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            _newgame();
            break;
        case 2:
            _rules();
            break;
        case 3:
            _highscore();
            break;
        case 4:
            exit(0);
        default:
            gotoxy(35, 12);
            printf("Wrong Choice :(");
            gotoxy(35, 13);
            printf("Press any key to enter again\n");
            _getch();
            system("cls");
            goto mainpage;
    }
}
void _newgame()
{
    system("cls");
    int choice;
    newgame:
    gotoxy(35, 2);
    printf("Enter choice:");
    gotoxy(35, 4);
    printf("1. Easy\n");
    gotoxy(35, 6);
    printf("2. Hard\n");
    gotoxy(35, 8);
    printf("3. Back to mainmenu\n");
    fflush(stdin);
    gotoxy(35, 10);
    printf(">  ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        system("cls");
        _quit_opt();
        _easy_quizoid();
    }
    else if(choice == 2)
    {
        system("cls");
        _quit_opt();
        _hard_quizoid();
    }
    else if(choice == 3)
        _mainpage();
    else
    {
        gotoxy(35, 12);
        printf("Wrong choice");
        gotoxy(35, 13);
        printf("Press any key to enter again  ");
        _getch();
        system("cls");
        goto newgame;
    }
}
void _easy_quizoid()
{
    system("cls");
    int i, j, k = 0, o = 0;
    FILE *fp1;
    fp1 = fopen("easy_quizoid.txt", "r");
    if(!fp1)
    {
        printf("file 'easy_quizoid' not found\n");
        exit(0);
    }
    //store questions and options in these arrays
    char array_ques[101][300], array_opt[20][5];
    while(fgets(array_ques[k], 299, fp1) != NULL)
    {
        for(i = 0; i < 4; i++)
        {
            k++;
            fgets(array_ques[k], 299, fp1);
        }
        //store answers in array_opt
        fgets(array_opt[o], 4, fp1);
        o++;
        k++;
    }
    fclose(fp1);
    array_ques[k][0] = '\0';
    i = 0;
    k = 0;
    int flag = 0, score = 0, answer;
    while(array_ques[i][0] != '\0')
    {
        //display question and its options
        for(j = 0; j < 5; j++)
        {
            gotoxy(2, 1+j);
            printf("%s", array_ques[i]);
            i++;
        }
        //input answer
        gotoxy(2, 8);
        printf("Enter answer:  ");
        fflush(stdin);
        scanf("%d", &answer);
        //press -1 to exit the quiz
        if(answer == -1)
        {
            flag = 1;
            break;
        }
        //check if answer correct and update score
        if(answer == (array_opt[k][0]-48))
        {
            gotoxy(2, 10);
            printf("Correct!!\n");
            score += 10;
            k++;
        }
        else
        {
            gotoxy(2, 10);
            printf("Wrong!! Correct option is %c\n", array_opt[k][0]);
            k++;
        }
        gotoxy(2, 12);
        printf("Press any key for next question\n");
        _getch();
        system("cls");
    }
    if(flag == 1)
    {
        system("cls");
        gotoxy(35, 2);
        printf("You Quit the quiz\n");
        gotoxy(35, 4);
        printf("Your score is: %d\n", score);
        gotoxy(35, 6);
        printf("Press any key to continue  ");
        _getch();
        goto playagain;
    }
    else
    {
        int highScore;
        FILE *h_score;
        h_score = fopen("easy_high_Score.txt","r");
        if(!h_score)
        {
            printf("file 'easy_high_Score.txt' not found\n");
            printf("Please move the file 'easy_high_Score.txt' to the current program folder\n");
            exit(0);
        }
        fscanf(h_score, "%d", &highScore);
        fclose(h_score);
        if(highScore < score)
        {
            gotoxy(40, 2);
            printf("Highscore!!");
            h_score = fopen("high_Score.txt","w");
            if(!h_score)
            {
                printf("file 'high_Score.txt' not found\n");
                printf("Please move the file 'high_Score.txt' to the current program folder\n");
                exit(0);
            }
            fprintf(h_score, "%d", score);
            fclose(h_score);
        }
        else if(highScore == score)
        {
            gotoxy(40, 2);
            printf("Highscore!!");
        }
        gotoxy(30, 3);
        printf("_____________________________________________");
        gotoxy(30, 5);
        printf("You completed the quiz");
        gotoxy(30, 7);
        printf("Your score is: %d/200\n", score);
        gotoxy(30, 8);
        printf("_____________________________________________\n\n");
        //
        gotoxy(30, 10);
        printf("Press any key to continue  ");
        _getch();
    }
    //playagain?
    playagain:
    system("cls");
    gotoxy(35, 2);
    printf("____________________________________");
    gotoxy(35, 4);
    printf("Wanna play again?(y/n)");
    gotoxy(35, 5);
    printf("____________________________________");
    gotoxy(35, 7);
    printf(">  ");
    int play_choice;
    fflush(stdin);
    scanf("%c", &play_choice);
    if(play_choice == 'y' || play_choice == 'Y')
        _mainpage();
    else if(play_choice == 'n' || play_choice == 'N')
        _quit_page();
    else
    {
        gotoxy(35, 9);
        printf("Wrong choice!!");
        gotoxy(35, 10);
        printf("Press any key to enter choice again  ");
        _getch();
        goto playagain;
    }
}
void _rules()
{
    system("cls");
    gotoxy(35, 2);
    printf("_________________________________________");
    gotoxy(50, 4);
    printf("INSTRUCTIONS");
    gotoxy(35, 5);
    printf("_________________________________________");
    gotoxy(35, 7);
    printf("1. Quiz comprises of two sections :");
    gotoxy(35, 9);
    printf("\ti.  Easy");
    gotoxy(35, 10);
    printf("\tii. Hard");
    gotoxy(35, 12);
    printf("2. There are 20 questions in each section.");
    gotoxy(35, 14);
    printf("3. Correct answer will give 10 points.");
    gotoxy(35, 16);
    printf("4. No negative marking for wrong answer.");
    gotoxy(35, 18);
    printf("5. After beginning the quiz, quit it anytime by just entering -1.");
    gotoxy(35, 20);
    printf("6. You can check the highscore in \'highscore\' section.");
    gotoxy(35, 22);
    printf("\t\t\tALL THE BEST");
    gotoxy(35, 24);
    printf("\t\tPress any key for Mainpage");
    _getch();
    _mainpage();
}
void _highscore()
{
    FILE *easy_score, *hard_score;
    int easyHighScore, hardHighScore;
    easy_score = fopen("easy_high_score.txt","r");
    if(!easy_score)
    {
        printf("file 'easy_high_score.txt' not found\n");
        printf("Please move the file 'easy_high_score.txt' to the current program folder\n");
        exit(0);
    }
    fscanf(easy_score, "%d", &easyHighScore);
    fclose(easy_score);
    // retrieve highscore for hard game
    hard_score = fopen("hard_high_score.txt","r");
    if(!hard_score)
    {
        printf("file 'hard_high_score.txt' not found\n");
        printf("Please move the file 'hard_high_score.txt' to the current program folder\n");
        exit(0);
    }
    fscanf(hard_score, "%d", &hardHighScore);
    fclose(hard_score);
    //print highscore
    system("cls");
    gotoxy(35, 2);
    printf("____________________________________");
    gotoxy(35, 4);
    printf("************************************");
    gotoxy(35, 5);
    printf("____________________________________");
    gotoxy(45, 7);
    printf("Highscore:");
    gotoxy(45, 9);
    printf("Easy:  %d", easyHighScore);
    gotoxy(45, 11);
    printf("Hard:  %d", hardHighScore);
    gotoxy(35, 12);
    printf("____________________________________");
    gotoxy(35, 14);
    printf("************************************");
    gotoxy(35, 15);
    printf("____________________________________");
    gotoxy(40, 18);
    printf("Press any key for Mainpage  ");
    _getch();
    _mainpage();
}
void _hard_quizoid()
{
    system("cls");
    int i, j, k = 0, o = 0;
    FILE *fp1;
    fp1 = fopen("hard_quizoid.txt", "r");
    if(!fp1)
    {
        printf("file 'hard_quizoid' not found\n");
        exit(0);
    }
    //store questions and options in these arrays
    char array_ques[101][300], array_opt[20][5];
    while(fgets(array_ques[k], 299, fp1) != NULL)
    {
        for(i = 0; i < 4; i++)
        {
            k++;
            fgets(array_ques[k], 299, fp1);
        }
        //store answers in array_opt
        fgets(array_opt[o], 4, fp1);
        o++;
        k++;
    }
    fclose(fp1);
    array_ques[k][0] = '\0';
    i = 0;
    k = 0;
    int flag = 0, score = 0, answer;
    while(array_ques[i][0] != '\0')
    {
        //display question and its options
        for(j = 0; j < 5; j++)
        {
            gotoxy(2, 1+j);
            printf("%s", array_ques[i]);
            i++;
        }
        //input answer
        gotoxy(2, 8);
        printf("Enter answer:  ");
        fflush(stdin);
        scanf("%d", &answer);
        //press -1 to exit the quiz
        if(answer == -1)
        {
            flag = 1;
            break;
        }
        //check if answer correct and update score
        if(answer == (array_opt[k][0]-48))
        {
            gotoxy(2, 10);
            printf("Correct!!\n");
            score += 10;
            k++;
        }
        else
        {
            gotoxy(2, 10);
            printf("Wrong!! Correct option is %c\n", array_opt[k][0]);
            k++;
        }
        gotoxy(2, 12);
        printf("Press any key for next question\n");
        _getch();
        system("cls");
    }
    if(flag == 1)
    {
        system("cls");
        gotoxy(35, 2);
        printf("You Quit the quiz\n");
        gotoxy(35, 4);
        printf("Your score is: %d\n", score);
        gotoxy(35, 6);
        printf("Press any key to continue  ");
        _getch();
        goto playagain;
    }
    else
    {
        int highScore;
        FILE *h_score;
        h_score = fopen("hard_high_score.txt","r");
        if(!h_score)
        {
            printf("file 'hard_high_score.txt' not found\n");
            printf("Please move the file 'hard_high_score.txt' to the current program folder\n");
            exit(0);
        }
        fscanf(h_score, "%d", &highScore);
        fclose(h_score);
        if(highScore < score)
        {
            gotoxy(40, 2);
            printf("Highscore!!");
            h_score = fopen("hard_high_score.txt","w");
            if(!h_score)
            {
                printf("file 'hard_high_score.txt' not found\n");
                printf("Please move the file 'hard_high_score.txt' to the current program folder\n");
                exit(0);
            }
            fprintf(h_score, "%d", score);
            fclose(h_score);
        }
        else if(highScore == score)
        {
            gotoxy(40, 2);
            printf("Highscore!!");
        }
        gotoxy(30, 3);
        printf("_________________________________________");
        gotoxy(30, 5);
        printf("You completed the quiz");
        gotoxy(30, 7);
        printf("Your score is: %d/200\n", score);
        gotoxy(30, 8);
        printf("_________________________________________");
        gotoxy(30, 10);
        printf("Press any key to continue  ");
        _getch();
    }
    //playagain?
    playagain:
    system("cls");
    gotoxy(35, 2);
    printf("____________________________________");
    gotoxy(35, 4);
    printf("Wanna play again?(y/n)");
    gotoxy(35, 5);
    printf("____________________________________");
    gotoxy(35, 7);
    printf(">  ");
    int play_choice;
    fflush(stdin);
    scanf("%c", &play_choice);
    if(play_choice == 'y' || play_choice == 'Y')
        _mainpage();
    else if(play_choice == 'n' || play_choice == 'N')
        _quit_page();
    else
    {
        gotoxy(35, 9);
        printf("Wrong choice!!");
        gotoxy(35, 10);
        printf("Press any key to enter choice again  ");
        _getch();
        goto playagain;
    }
}

void _quit_opt()
{
    gotoxy(35, 2);
    printf("After the quiz begins");
    gotoxy(35, 4);
    printf("Press -1 to quit the quiz anytime\n");
    gotoxy(35, 6);
    printf("Now press any key to begin the quiz  ");
    gotoxy(35, 8);
    printf("All The Best :)  ");
    _getch();
    system("cls");
}

void _quit_page()
{
    system("cls");
    printf("\n\t\t                         :::::::::::::::::::::::::::::::::::::");
    printf("\n\t\t                         ::                                 ::");
    printf("\n\t\t                         ::     ***********************     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     *      THANK YOU      *     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     *                     *     ::");
    printf("\n\t\t                         ::     ***********************     ::");
    printf("\n\t\t                         ::                                 ::");
    printf("\n\t\t                         :::::::::::::::::::::::::::::::::::::\n\n");
    printf("\n\n\n\n");
}
int main()
{
    //this is the welcome page
    _welcomepage();
    choice:  //goto label... if user enters incorrect choice then the process of mainmenu will repeat
    switch(_loginsignupmenu())
    {
    case 1:
        _signup();
        _login();   // after signup now login to begin the quiz
        break;
    case 2:
        _login();
        break;
    case 3:
        exit(0);
    default:
        gotoxy(35, 12);
        printf("Wrong Choice...Press Enter For Mainmenu\n");
        _getch();
        goto choice;
    }
    return 0;
}
