#include <stdio.h>

int main()
{
    FILE *datatxt;

    datatxt = fopen("data.txt", "r"); /* open my file*/

    int x, y, c;                                    /* define almost all variables here*/
    int maxx0 = 0, maxx1 = 0, maxy0 = 0, maxy1 = 0; /* give 0 to max, because ı compare below*/
    int minx0, minx1, miny0, miny1;
    int k0 = 1, k1 = 1; /* just for if statements*/
    int R1, R2, R3, R4;
    int sepx, sepy;
    int main_maxy, main_miny, main_maxx, main_minx;
    int r1_1 = 0, r2_1 = 0, r3_1 = 0, r4_1 = 0; /*finding regions label*/
    int r1_0 = 0, r2_0 = 0, r3_0 = 0, r4_0 = 0;
    int error = 0;
    int minerror = 10000;
    int updtsepx, updtsepy, updtR1, updtR2, updtR3, updtR4; /*updated values*/

    while (fscanf(datatxt, "%d %d %d", &x, &y, &c) != EOF) /*read fil from head to end*/
    {

        if (c == 0) /* for class 0*/
        {
            if (k0 == 1) /* given any min values to my x and y to compare*/
            {
                minx0 = x;
                miny0 = y;
                k0--;
            }

            if (x <= minx0) /* compare evertyhing and finding min and max values for class 0*/
            {
                minx0 = x;
            }
            if (x >= maxx0)
            {
                maxx0 = x;
            }
            if (y <= miny0)
            {
                miny0 = y;
            }
            if (y >= maxy0)
            {
                maxy0 = y;
            }
        }
        else if (c == 1) /* for class 1*/
        {
            if (k1 == 1) /* given any min values to my x and y to compare*/
            {
                minx1 = x;
                miny1 = y;
                k1--;
            }

            if (x <= minx1) /* compare evertyhing and finding min and max values for class 1*/
            {
                minx1 = x;
            }
            if (x >= maxx1)
            {
                maxx1 = x;
            }
            if (y <= miny1)
            {
                miny1 = y;
            }
            if (y >= maxy1)
            {
                maxy1 = y;
            }
        }
    }
    fclose(datatxt); /* close the file*/

    if (miny0 < miny1) /*compare every value to find main min and main max*/
    {
        main_miny = miny0;
    }
    else
    {
        main_miny = miny1;
    }

    if (minx0 < minx1)
    {
        main_minx = minx0;
    }
    else
    {
        main_minx = minx1;
    }

    if (maxy0 < maxy1)
    {
        main_maxy = maxy1;
    }
    else
    {
        main_maxy = maxy0;
    }

    if (maxx0 < maxx1)
    {
        main_maxx = maxx1;
    }
    else
    {
        main_maxx = maxx0;
    }

    for (sepx = main_minx; sepx <= main_maxx; sepx++) /* take sepx from min values to max values*/
    {

        for (sepy = main_miny; sepy <= main_maxy; sepy++) /* take sepy from min values to max values*/
        {
            r1_1 = 0, r2_1 = 0, r3_1 = 0, r4_1 = 0; /* give 0 to regions*/
            r1_0 = 0, r2_0 = 0, r3_0 = 0, r4_0 = 0;

            datatxt = fopen("data.txt", "r");

            while (fscanf(datatxt, "%d %d %d", &x, &y, &c) != EOF) /*read file from head to end*/
            {
                if (x <= sepx && y > sepy) /* determining region 1 */
                {
                    if (c == 1)
                    {
                        r1_1++;
                    }
                    if (c == 0)
                    {
                        r1_0++;
                    }
                }
                else if (x > sepx && y > sepy) /* determining region 2 */
                {
                    if (c == 1)
                    {
                        r2_1++;
                    }
                    if (c == 0)
                    {
                        r2_0++;
                    }
                }
                else if (x <= sepx && y <= sepy) /* determining region 3 */
                {
                    if (c == 1)
                    {
                        r3_1++;
                    }
                    if (c == 0)
                    {
                        r3_0++;
                    }
                }
                else if (x > sepx && y <= sepy) /* determining region 4 */
                {
                    if (c == 1)
                    {
                        r4_1++;
                    }
                    if (c == 0)
                    {
                        r4_0++;
                    }
                }
            }

            fclose(datatxt); /* close the file*/

            error = 0; /* give 0 to error*/

            if (r1_1 > r1_0) /*finding R1 class and counting errors */
            {
                R1 = 1;
                error += r1_0;
            }
            else
            {
                R1 = 0;
                error += r1_1;
            }
            if (r2_1 > r2_0) /*finding R2 class and counting errors */
            {
                R2 = 1;
                error += r2_0;
            }
            else
            {
                R2 = 0;
                error += r2_1;
            }
            if (r3_1 > r3_0) /*finding R3 class and counting errors */
            {
                R3 = 1;
                error += r3_0;
            }
            else
            {
                R3 = 0;
                error += r3_1;
            }
            if (r4_1 > r4_0) /*finding R4 class and counting errors */
            {
                R4 = 1;
                error += r4_0;
            }
            else
            {
                R4 = 0;
                error += r4_1;
            }

            if (error < minerror) /* updated my values*/
            {
                minerror = error;
                updtsepx = sepx;
                updtsepy = sepy;
                updtR1 = R1;
                updtR2 = R2;
                updtR3 = R3;
                updtR4 = R4;
            }
        }
    }

    FILE *test1;     /*opening test1 file*/
    FILE *testfinal; /*opening testfinal file*/
    int counter = 0; /*define some counters*/
    double success_counter = 0;
    double success_rate = 0;
    int key = 0; /* taken a number from fscanf*/

    test1 = fopen("test 1.txt", "r"); /*opening file*/

    while (fscanf(test1, "%d %d %d", &x, &y, &c) != EOF) /*read file from head to end*/
    {
        counter++;
        if (x <= updtsepx && y > updtsepy && updtR1 == c) /*comparing test and data regions then count them*/
        {
            success_counter++; /*R1*/
        }
        else if (x > updtsepx && y > updtsepy && updtR2 == c) /* R2*/
        {
            success_counter++;
        }
        else if (x <= updtsepx && y <= updtsepy && updtR3 == c) /* R3*/
        {
            success_counter++;
        }
        else if (x > updtsepx && y <= updtsepy && updtR4 == c) /* R4*/
        {
            success_counter++;
        }
    }
    fclose(test1);

    success_rate = (success_counter / counter) * 100; /*calculating success rate*/

    while (1)
    {

        printf("\n1: Explore Data\n2: Train Model \n3: Test Model \n4: EXIT \n\n "); /* write menu*/
        printf("Enter your choice:");                                                /*take a integer from user*/
        scanf("%d", &key);
        switch (key)
        {
        case 1: /*ıf print 1 , you started first part in the pdf*/
            printf("\nClass 0: X in [%d %d], Y in [%d %d]\n", minx0, maxx0, miny0, maxy0);
            printf("Class 1: X in [%d %d], Y in [%d %d]\n", minx1, maxx1, miny1, maxy1);
            break;
        case 2: /*ıf print 2 , you started second part in the pdf*/
            printf("\nSeparator coordinates: X = %d, Y = %d \n", updtsepx, updtsepy);
            printf("Training error of the model: %d\n", minerror);
            printf("Labels of the regions R1: %d  R2: %d  R3: %d  R4: %d\n", updtR1, updtR2, updtR3, updtR4);
            break;
        case 3: /*ıf print 3 , you started third part in the pdf*/
            printf("\nYour success : %%%0.2f\n", success_rate);
            testfinal = fopen("test-final.txt", "r"); /*opening file*/

            while (fscanf(testfinal, "%d %d", &x, &y) != EOF)
            {
                if (x <= updtsepx && y > updtsepy) /*determining R1 are and compare them*/
                {
                    c = updtR1;
                }
                else if (x > updtsepx && y > updtsepy) /*determining R2 are and compare them*/
                {
                    c = updtR2;
                }
                else if (x <= updtsepx && y <= updtsepy) /*determining R3 are and compare them*/
                {
                    c = updtR3;
                }
                else if (x > updtsepx && y <= updtsepy) /*determining R4 are and compare them*/
                {
                    c = updtR4;
                }
                printf("X: %d, Y: %d, Class: %d\n", x, y, c);
            }
            fclose(testfinal);
            break;
        case 4:
            printf("\nExiting\n");
            return 0;
        default:
            printf("\nWrong choice, please select from 1 to 4\n"); /* take a wrong choices*/
            return 1;
            break;
        }
    }

    return 0;
}
