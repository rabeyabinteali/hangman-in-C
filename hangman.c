#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
	char words[][30]= {
	"Silent Hill",
    "War Dogs",
    "Seoul Station",
    "Universal Solider",
    "Lord of the Rings",
    "Power Rangers",
    "Attack on Titan",
    "The Deep Blue Sea",
    "The Terminator",
    "War of the Worlds",
    "Fury",
    "Oblivion",
    "Black Hawk Down",
    "Ultraviolet",
    "Iron Man",
    "Blade",
    "The Conjuring",
    "The Nun",
    "Thor",
    "The Avengers",
    "Finch",
    "Matrix",
    "Red Baron",
    "Once Upon A Time In Mumbai",
    "Resident Evil",
    "Evil Dead",
    "Dabbe",
    "Midsommar",
    "Saw",
    "The Blair Witch Project",
    "V For Vendetta",
    "Train To Busan",
    "Peninsula",
    "Kingdom of Heaven",
    "The Prince of Egypt",
    "The Wolverine",
    "Independence Day",
    "Carmilla",
    "Alien",
    "The Revenant",
    "Prometheus",
    "The Adventures of Tintin",
    "Alpha",
    "Life Is Beautiful",
    "Downfall",
    "We Were Soldiers",
   " Armageddon",
    "Life Of Pi",
    "The Shawshank Redemption",
    "The Green Mile",
    "Dune",
    "Gravity",
    "Inception",
    "Dunkirk",
    "Darkest Hour",
    "The Dark Knight",
    "The Suicide Squad",
    "Waterworld",
    "Iron Sky"

    };
//gaps and guesses
char hangmanrevise(char str[30])
{
    int i;
    printf("\n");
    for(i=0;i<strlen(str);i++)
    {
    if(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z')))
        {
            printf("%c ",str[i]);
        }
    else if(str[i]=='0')
        {
            printf("_ ");
        }
    else if(str[i]=='*')//* was gap hence returning gap sign
        {
            printf("/ ");
        }
    else if(str[i]=='#')//vowel sign hence returning vowel sign #
        {
            printf("# ");
        }
    }
}
//printing the hangman version of string with gaps
char hangman(char str[30])
{
   int i;
    for(i=0;i<strlen(str);i++)
    {
        if((str[i]=='a')||(str[i]=='e')||(str[i]=='i')||(str[i]=='o')||(str[i]=='u')||(str[i]=='A')||(str[i]=='E')||(str[i]=='I')||(str[i]=='O')||(str[i]=='U'))
        printf("# ");//vowel sign
        else if(str[i]!=' ')
        printf("_ ");
        else
        printf("/ ");
    }
}
//program will only take the last character entered.
char cleanstr(char str[8])
{
    int i;
    char ch;
    for(i=0;i<strlen(str);i++)
    {
        if(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z')))
        ch=str[i];
    }
    return ch;
}
//finds number of alphabets in string
int clstrlen(char str[30])
{
    int i,l=0,j,m=0;
    for(i=0;i<strlen(str);i++)
    {
        if(((str[i]>='a')&&(str[i]<='z'))||((str[i]>='A')&&(str[i]<='Z')))
        l++;
    }
    return l;
}
//checks how many times character is present in a string
int chck( char ch, char str[30])
{
    int i,v=0;
    for(i=0;i<strlen(str);i++)
    {
        if(ch==str[i])
        v++;
    }
    return v;
}
//returns character in opposite case
char chver(char ch)
{
    if((ch>='a')&&(ch<='z'))
    ch=ch-32;
    else if((ch>='A')&&(ch<='Z'))
    ch=ch+32;

    return ch;
}
//return characters from str2(correctguess) to str3(new_word) in order of str1(word)
char reorder(char str1[30], char str2[30],char str3[30])
{
    if(clstrlen(str1)>0){
        int i,j;
        for(i=0;i<30;i++)//for the length of str1 run this loop
        {
            if((str1[i]=='a')||(str1[i]=='e')||(str1[i]=='i')||(str1[i]=='o')||(str1[i]=='u')||(str1[i]=='A')||(str1[i]=='E')||(str1[i]=='I')||(str1[i]=='O')||(str1[i]=='U'))//retirn # for vowel
            str3[i]='#';
            for(j=0;j<30;j++)//for the legnth of str2 run this loop
            {
                if((str2[j]==str1[i])||(chver(str2[j])==str1[i]))
                    str3[i]=str2[j]; //returning value of str2 to str3 in order of str1
            }
            if(str1[i]==' ')
                str3[i]='*';//return * for gap
        }
    }
}
//enter main function of the program
int main()
{
    level1:
    printf("\nRules of the Game: \n1. # represents vowel character.\n2. / represents gap.\n3. _ represents consonant character.\n4. Both UPPERCASE and lowercase alphabets are acceptable.\n5. Only alphabetical characters are present in the movie name.\n6. Enter one character at a time, in case of multiple characters only last entered character will be registered\n----Enjoy the game!----\n\n\n");
	srand(time(0));
	int wordchoice, lives =7, corrects = 0,i,j=0, oldcorrects=0, chlen,k,v=0,r=0,wc=0;
	char guess[8];//current guess string
	char takenguess[30];//taken guess string
	char correctguess[30];//correct guess string
	char new_word[30];//new string with guessed characters and gaps
	char wrongguess[30];//new string with wrong guesses
	char instruction[5];
	char ins;
        	for(i=0;i<strlen(correctguess);i++)
        	{
        	   correctguess[i]='0';
        	}
        	for(i=0;i<strlen(takenguess);i++)
        	{
        	   takenguess[i]='0';
        	}
        	for(i=0;i<strlen(takenguess);i++)
        	{
        	   wrongguess[i]='0';
        	}
	char ch, vch;
	wordchoice= (rand()%67);
	chlen= clstrlen(words[wordchoice]);//total characters in movie name
    hangman(words[wordchoice]);
            for(i=0;i<strlen(words[wordchoice]);i++)
            {
                new_word[i]='0';
            }
            for(i=(strlen(words[wordchoice]));i<strlen(new_word);i++)
            {
                new_word[i]='1';
            }
    level2:
    for(i=0;i<27;i++)//running this loop for maximum character limit plus error limit times
    {

         if(lives==0)
        {
        break;//break the loop if lives is 0
        }

         if(corrects==chlen)
        {
        break;//break the loop if number of correct guesses is equal to number of alphabets in movie name
        }
            printf("\nLives Remaining: %d",lives);
            printf("\nEnter your guess: ");
            scanf("%s",&guess);
            ch=cleanstr(guess);//returning the last character entered
            vch=chver(ch);//opposite case of entered character
            v=chck(ch,words[wordchoice])+chck(vch,words[wordchoice]);//number of times character appears in movie name
            r=chck(ch,takenguess)+chck(vch,takenguess);//checks if alphabet has been guessed before
            if(v==0){
                wrongguess[wc]=ch;
                wc++;
            }
            if(r==0)
            {
                    corrects=corrects+v;//number of corrects obtained
                        if(corrects>oldcorrects)
                        {
                            correctguess[j]=ch;
                            j++;
                            reorder(words[wordchoice],correctguess,new_word);//reordering
                            printf("\nYou guessed right.\nIncorrect guesses so far: ");
                            for(j=0;j<clstrlen(wrongguess);j++)
                            {
                                if(((wrongguess[j]>='a')&&(wrongguess[j]<='z'))||((wrongguess[j]>='A')&&(wrongguess[j]<='Z')))
                                {
                                printf("%c ",wrongguess[j]);//print correct guesses so far

                                }
                            }
                            oldcorrects=corrects;
                            hangmanrevise(new_word);
                        }
                        else
                        {
                            reorder(words[wordchoice],correctguess,new_word);//reordering
                            printf("\nLost a live.\nIncorrect guesses so far: ");
                            if(clstrlen(wrongguess)==0)
                            {
                            printf("None So Far\nWord was: ");//zero correct guesses so far
                            hangman(words[wordchoice]);//print hangman version again

                            }
                            if(clstrlen(wrongguess)>0)
                            {

                                //reorder(words[wordchoice],wrongguess,new_word);//reordering
                                for(j=0;j<clstrlen(wrongguess);j++)
                                {
                                    if(((wrongguess[j]>='a')&&(wrongguess[j]<='z'))||((wrongguess[j]>='A')&&(wrongguess[j]<='Z')))
                                    printf("%c ",wrongguess[j]);//print correct guesses so far
                                }
                            }


                            lives= lives-1;
                            hangmanrevise(new_word);
                        }
            takenguess[i]=ch;//stores alphabet to takenguess string.
            }
            else
            {
                printf("You have already guessed %c",ch);
            }
    }
    if(corrects==chlen)
    {
    	printf("\nYou won.\nWord was: %s\n To start a new game press 'n'.\n To quit playing press 'q'.\n",words[wordchoice]); //all characters have been guessed
    	scanf("%s",&instruction);
    	ins=cleanstr(instruction);
    	if((ins=='n')||(chver(ins)=='n'))
            {
                goto level1;//restarting the program
            }
        else if((ins=='q')||(chver(ins)=='q'))
    	    {
    	        return 0;//exiting the program
    	    }
    }
    else if(lives==0)
    {
    	printf("\nYou lost.\nWord was: %s\n To start a new game press 'n'.\n To quit playing press 'q'.\n",words[wordchoice]); //all lives are lost
    	scanf("%s",&instruction);
    	ins=cleanstr(instruction);
    	if((ins=='n')||(chver(ins)=='n'))
            {
                goto level1;//restarting the program
            }
        else if((ins=='q')||(chver(ins)=='q'))
    	    {
    	        return 0;//exiting the program
    	    }

    }
    else
    {
    	printf("\nSorry, you ran out of tries.\n To play resume playing press 'r'.\n To start a new game press 'n'.\n To quit playing press 'q'.\n"); //ran out of tries
    	scanf("%s",&instruction);
    	ins=cleanstr(instruction);
	    if((ins=='r')||(chver(ins)=='r'))
	        {
	            goto level2;//resuming the trials
	        }
        else if((ins=='n')||(chver(ins)=='n'))
            {
                goto level1;//restarting the program
            }
        else if((ins=='q')||(chver(ins)=='q'))
    	    {
    	        return 0;//exiting the program
    	    }
    }
}
