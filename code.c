#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include <errno.h>
#include <locale.h>
#include <windows.h>


typedef struct
{
    char name_of_centre[max];
    float points;
    char subject[max];
}student_t;

student_t st[max];

typedef struct
{
    char name_of_university[max];
    char faculty[max][max];
    int counter_for_statistics;
    int counter_of_students;
}student_b;

student_b sm[max];

int M = 0;

int N = 0;

int insert_of_universities( char question[max] )
{
    FILE *fp;
    char str[max][max];
    int j = 0, i;
    fp = fopen("UniversityList.txt","r");
    if( fp == NULL )
    {
        perror("Error file name\n");
        return 1;
    }

    else
    {
        while( fgets( str[j], max, fp ) != 0 )
        {
            strcpy( sm[M].name_of_university, str[j] );
            j++;
            M++;
        }
        fclose(fp);
        int i, flag = 0;
        for( i = 0; i < M; i++ )
        {
            if( strcmp( question, sm[i].name_of_university ) == 0 )
                flag = 1;
        }
        if( flag == 0 )
        {
            return 1;
        }
        else
        {
            printf("��� ������ �������, ����� �� ������� ������\n");
            return 0;
        }
    }
}

void count_number_of_students()
{
    int i = 0, j = 0, k = 0, m, n, n1;
    char str[max][max], univer[max][max], fac[max][max], str1[max][max];
    FILE *fp;
    fp = fopen("blank.txt","r");
    if( fp == NULL )
    {
        perror("Error file name\n");
        return 1;
    }

    else
    {
        int count_of_students = 0, count_of_universitites = 0, flag = 0, flag1 = 0;
        while( fscanf( fp, "%s", str[j] ) != EOF )
        {
            if( strcmp( str[j], "Name:" ) == 0 )
            {
                count_of_students++;
            }

            else if( strcmp( str[j], "University:" ) == 0 )
            {
                flag = 1;
            }

            else if( strcmp( str[j], "Faculty:" ) == 0 )
            {
                flag1 = 1;
            }

            else if( flag == 1 )
            {
                flag = 0;
                strcpy( univer[i], str[j] );
                i++;
            }

            else if( flag1 == 1 )
            {
                flag1 = 0;
                strcpy( fac[k], str[j] );
                k++;
            }
            j++;
        }

        printf("����� ���������� c�������� �����: %d \n", count_of_students);

        int count1 = 0;
        ///here we are goona calculate all universities

        for( m = 0; m < i; m++ )
        {
            int count = 1;
            flag = 0;
            for( n1 = 0; n1 < count1; n1++ )
            {
                if( strcmp( str1[n1], univer[m] ) == 0 )
                {
                    flag = 1;
                }
            }
            if( flag == 1 )
                continue;

            for( n = m + 1; n < i; n++ )
            {
                if( strcmp( univer[m], univer[n] ) == 0 )
                {
                    count++;
                }
            }
            strcpy( str1[count1], univer[m] );
            count1++;
            printf(" for university %s there are %d number of books\n ", univer[m], count );
        }
    }
}

void searchPassport()
{
	char passportID[max];
	char str[max];
	int flag = 0;
    FILE *fp;
	fp = fopen("blank.txt", "r");
	if (fp == NULL)
	{
		printf("Error, could not open the file\n");
		fflush(stdout);
	}
	else
	{
		printf("Enter passport code: ");
		fflush(stdout);
		scanf("%s",passportID);
		while(fscanf(fp, "%s", str)!=EOF)
		{
			if(strcmp("Passport:", str) == 0)
			{
				flag = 1;
				continue;
			}
			if (flag == 1)
			{
			    flag = 0;
				if(strcmp( str, passportID ) == 0)
				{
					printf("There is such a student\t");
					fflush(stdout);
				}
				else
				{
					printf("There is NO such a student\t");
					fflush(stdout);
				}
			}
		}
	}
}

void registrate_to_university()
{
    	char name[max], surname[max], university[max], faculty[max], email[max], date[max], passport[max];
		char number[max];
		FILE *fp;
	    if((fp= fopen("blank.txt","a"))==NULL)
	    {
	        perror("Error file name\n");
	        return 1;
	    }
	    puts("all information about you");
	    printf("Enter your first name: \n");

	    scanf("%s", name);

	    printf("Enter your last name: \n");
	    scanf("%s", surname);

	    printf("Enter your university: \n");
	    scanf("%s", university);

	    printf("Enter your faculty: \n");
	    scanf("%s", faculty);

	    printf("Enter your email: \n");
	    scanf("%s", email);

	    printf("Enter your date 01.01.1991 format: \n");
	    scanf("%s", date);

	    printf("Enter your passport: \n");
	    scanf("%s", passport);

	    printf("Enter your phone number format +9989: \n");
	    scanf("%s", number);


	    fprintf(fp,"Name: %s\n", name);
	    fprintf(fp,"Surname: %s\n", surname);
	    fprintf(fp,"University: %s\n", university);
	    fprintf(fp,"Faculty: %s\n", faculty);
	    fprintf(fp,"Email: %s\n", email);
	    fprintf(fp,"Date: %s\n", date);
	    fprintf(fp,"Passport: %s\n", passport);
	    fprintf(fp,"Number: %s\n", number);
        fprintf( fp, "\n\n", stdout );
	    printf("Blank is ready, check document\n\n");
	    fclose(fp);
}

void universities()
{
    char name[max][max], str[max];
    float points;
    int i = 0, j = 0;
    char question[max];
    printf("������� �������� ������������ ������� �����: ");
    scanf("%s", question);
    if( insert_of_universities(question) == 1 )
        printf("�� � ��� ���� ����� ������!!!\n");

    FILE *fp;
    fp = fopen( "UniversityInfo.txt", "r" );
    if( fp == NULL )
    {
        perror("there is no such kinda file!!!");
    }

    else
    {
        int flag = 0;
        while( fscanf( fp, "%s", name[j] ) != EOF )
        {
            j++;
        }
        fclose(fp);
        for( i = 0; i < j; i++ )
        {
            if( strcmp( name[i], "Faculties:" ) == 0 )
                printf("\n");
            else if( strcmp( name[i], "Exams:" ) == 0 )
                printf("\n");
            else if( strcmp( name[i], "Address:" ) == 0 )
                printf("\n");
            else if( strcmp( name[i], "Email:" ) == 0 )
                printf("\n");
            else if( strcmp( name[i], "Phone:" ) == 0 )
                printf("\n");
            else if( strcmp( name[i], "end" ) == 0 )
            {
                printf("\n\n");
                continue;
            }
            printf("%s", name[i]);
        }
    }
    printf("\n\n");
}

void teachers()
{

}

void tutors()
{

}

void samples()
{

}

void studying_centers()
{
    float points, max_value = 0;
    char name[max], choice[max];
    int i, j;
    FILE *fp;
    fp = fopen( "studing_centres.txt", "r" );
    if( fp == NULL )
    {
        perror("there is no such kinda file!!!");
    }

    else
    {
        while( fgets(name, max, fp ) != EOF )
        {
            printf("%s\n", name);
        }
        fclose(fp);

        printf("maybe u wanna find some exact subject!!!");
        scanf("%s", choice);
        if( strcmp( choice, "yes" ) == 0 )
        {
            printf("enter the name of subject u are looking for: ");
            scanf("%s", choice);
            i = 0;
            while( fscanf(fp, "%s", name ) != EOF )
            {
                printf("%s\n", name);
                strcpy( st[N].name_of_centre, name );
                st[N].points = points;
                if( strcmp( name, choice ) == 0 )
                {
                    printf("%s\n", st[i].name_of_centre );
                }
                i++;
            }
            fclose(fp);
        }
    }

    printf("\n\nif u wish i can show u the list of top centers!!!\n ");
    printf("do u wish to see this list: ");
    scanf( "%s", choice );

    if( strcmp( choice, "yes" ) == 0 )
    {
        for( i = 0; i < N - 1; i++ )
        {
            for( j = i + 1; j < N; j++ )
            {
                if( st[i].points > st[j].points )
                {
                    points = st[i].points;
                    st[i].points = st[j].points;
                    st[j].points = points;
                    strcpy( name, st[i].name_of_centre );
                    strcpy( st[i].name_of_centre, st[j].name_of_centre );
                    strcpy( st[j].name_of_centre, name );
                }
            }
        }
        printf("\n\n");
        for ( i = 0; i < N; i++ )
        {
            printf( "%s %.2f\n", st[i].name_of_centre, st[i].points );
        }
    }

    printf("\n\nmaybe u need a center for some exact subject!!!\n");
    printf("input your subject and i will try to find something for u: ");
    scanf( "%s", choice );
    for ( i = 0; i < N; i++ )
    {
        if( strcmp( choice, st[i].subject ) == 0 )
        {

        }
    }

    printf(" \n\ni hope u got necessary info about our centers!!!\n ");
    printf("if u have other questions i am able to help u, maybe :)!!!\n\n\n\n\n");

}

int main()
{
    printf( "hello i am S.I.M.O, i am gonna be your provider\n" );
    printf( "i have info about all universities, \nteachers, \ntutors \nand obviously which kinda subjects u need to prepare to in order to pass exam!!!\n" );
    int choose;
    char *locale = setlocale( LC_ALL, "" );
    char choice[max];
    do
    {
        printf( "so tell me what u wanna find out, by choosing any categories: \n" );
        printf( "1. universities\n" );
        printf( "2. teachers\n" );
        printf( "3. tutors\n" );
        printf( "4. samples\n" );
        printf( "5. studying centers\n" );
        printf( "6. registration\n");
        printf( "7. search for registration\n");
        printf( "8. statistics\n");
        scanf("%d", &choose);
        if( choose == 1 )
        {
            universities();
        }

        else if( choose == 2 )
        {
            teachers();
        }

        else if( choose == 3 )
        {
            tutors();
        }

        else if( choose == 4 )
        {
            samples();
        }

        else if( choose == 5 )
        {
            studying_centers();
        }
        else if( choose == 6 )
        {
            registrate_to_university();
        }

        else if( choose == 7 )
        {
            searchPassport();
        }

        else if( choose == 8 )
        {
            count_number_of_students();
        }

        else
        {
            printf( "Ooops unfortunately we do not have such kinda service!!!\n" );
            printf("try again!!!!\n");
        }
        printf( "do u wanna continue: " );
        scanf( "%s", choice );
    }while( strcmp( choice, "stop" ) != 0 );

    printf( "so thank u for choosing us!!!\n\n" );

    getch();
    return 0;
}