/*
    Student Name: Christian Agosto
    Panther ID: 5768463
    Describtion: This program is desing to modify a given
	bmp file. The user will be given the choice to enlarge a picture,
	rotate it with a multiple of 90 and or flip it vertically or
	horizontally.

    I affirm that I wrote this program myself without any help
    form any other people or source from the internet.
*/
#include <stdlib.h>
#include "bmplib.h"
#include <string.h>
#include <stdio.h>
/*
 * This method enlarges a 24-bit, uncompressed .bmp file
 * that has been read in using readFile()
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the original number of rows
 * cols     - the original number of columns
 *
 * scale    - the multiplier applied to EACH OF the rows and columns, e.g.
 *           if scale=2, then 2* rows and 2*cols
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows (scale*rows)
 * newcols  - the new number of cols (scale*cols)
 */
int enlarge(PIXEL* original, int rows, int cols, int scale,
	    PIXEL** new, int* newrows, int* newcols)
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */
  int rowCounter = 0;
  int columnCounter = 0;
  int index = 0;
  int secondIndex = 0;

  *newrows = scale * rows;
  *newcols = scale * cols;

  if ((rows <= 0) || (cols <= 0))
  {
	  return -1;
  }

  *new = (PIXEL*)malloc((*newrows)*(*newcols)*sizeof(PIXEL));

  PIXEL* n = (*new);

  for (rowCounter = 0; rowCounter < rows; rowCounter++)
  {
	  for (index = scale; index > 0; index--)
	  {
		  for (columnCounter = 0; columnCounter < cols; columnCounter++)
		  {
			  PIXEL* o = original + rowCounter*cols + columnCounter;

			  for (secondIndex = scale; secondIndex > 0; secondIndex--)
			  {
				  *n++ = *o;
			  }
		  }
	  }
  }
  return 0;
}

/*
 * This method rotates a 24-bit, uncompressed .bmp file that has been read
 * in using readFile(). The rotation is expressed in degrees and can be
 * positive, negative, or 0 -- but it must be a multiple of 90 degrees
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 * rotation - a positive or negative rotation,
 *
 * new      - the new array containing the PIXELs, allocated within
 * newrows  - the new number of rows
 * newcols  - the new number of cols
 */
int rotate(PIXEL* original, int rows, int cols, int rotation,
	   PIXEL** new, int* newrows, int* newcols)
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */

  //constant for if statements
  const int MULTIPLE = 360;
  const int CHECK1 = 270;
  const int CHECK2_5 = -90;
  const int CHECK3 = 180;
  const int CHECK3_5 = -180;

  int rowCounter = 0;
  int columnsCounter = 0;

  if ((rows <= 0) || (cols <= 0))
  {
	  return -1;
  }

  *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));

  if (rotation % MULTIPLE  == 0)
  {
	  for (rowCounter = 0; rowCounter < rows; rowCounter++)
	  {
		  for (columnsCounter = 0; columnsCounter < cols; columnsCounter++)
		  {
			  PIXEL* o = original + rowCounter*cols + columnsCounter;
			  PIXEL* n = (*new) + rowCounter*cols + columnsCounter;
			  *n = *o;
		  }
	  }

	  return 0;
  }

  else if (rotation % MULTIPLE == CHECK1 || rotation % MULTIPLE == CHECK2_5)
  {
	  *newrows = cols;
	  *newcols = rows;

	  for (rowCounter = 0; rowCounter < rows; rowCounter++)
	  {
		  for (columnsCounter = 0; columnsCounter < cols; columnsCounter++)
		  {
			  PIXEL* o = original + rowCounter*cols + columnsCounter;
			  PIXEL* n = (*new) + columnsCounter*rows + (rows-rowCounter-1);
			  *n = *o;
		  }
	  }

	  return 0;
  }

  else if (rotation % MULTIPLE == CHECK3 || rotation % MULTIPLE == CHECK3_5)
  {
	  for (rowCounter = 0; rowCounter < rows; rowCounter++)
	  {
		  for (columnsCounter = 0; columnsCounter < cols; columnsCounter++)
		  {
			  PIXEL* o = original + rowCounter*cols + columnsCounter;
			  PIXEL* n = (*new) + (rows-rowCounter)*cols-(columnsCounter + 1);
			  *n = *o;
		  }
	  }

	  return 0;
  }

  else
  {
	  *newrows = cols;
	  *newcols = rows;

	  for (rowCounter = 0; rowCounter < rows; rowCounter++)
	  {
		  for (columnsCounter = 0; columnsCounter < cols; columnsCounter++)
		  {
			  PIXEL* o = original + rowCounter*cols + columnsCounter;
			  PIXEL* n = (*new) + (cols-columnsCounter-1)*rows + rowCounter;
			  *n = *o;
		  }
	  }
  }

  return 0;
}

/*
 * This method Vertically flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */

int verticalflip (PIXEL *original, PIXEL **new, int rows, int cols)
{
  /* THIS IS THE METHOD THAT YOU SHOULD WRITE */
  int row, col;

    if ((rows <= 0) || (cols <= 0)) return -1;

    *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));

    for (row = 0; row < rows; row++)
	{
		for (col=0; col < cols; col++)
		{
            PIXEL* o = original + row*cols + col;
            PIXEL* n = (*new) + (rows-1-row)*cols + col;
            *n = *o;
        }
	}

  return 0;
}

/*
 * This method horizontally flips a 24-bit, uncompressed bmp file
 * that has been read in using readFile().
 *
 * THIS IS GIVEN TO YOU SOLELY TO LOOK AT AS AN EXAMPLE
 * TRY TO UNDERSTAND HOW IT WORKS
 *
 * original - an array containing the original PIXELs, 3 bytes per each
 * rows     - the number of rows
 * cols     - the number of columns
 *
 * new      - the new array containing the PIXELs, allocated within
 */
int flip (PIXEL *original, PIXEL **new, int rows, int cols)
{
  int row, col;

  if ((rows <= 0) || (cols <= 0)) return -1;

  *new = (PIXEL*)malloc(rows*cols*sizeof(PIXEL));

  for (row=0; row < rows; row++)
    for (col=0; col < cols; col++)
	{
      PIXEL* o = original + row*cols + col;
      PIXEL* n = (*new) + row*cols + (cols-1-col);
      *n = *o;
    }

  return 0;
}

int main(int argc, char **argv)
{
	int rows = 0;
	int columns = 0;
	int update = 0;
	PIXEL *b, *nb;
	int newRows = 0;
	int newColumns = 0;
	int scale = 0;
	int degree = 0;
	char *output_file;

	extern char *optarg;
	extern int optind;
	int c, err = 0;
	int sflag = 0;
	int rflag = 0;
	int fflag = 0;
	int vflag = 0;
	int oflag = 0;
	static char usage[] =
	"%./bmptool [-s scale | -r degree | -f | -v ] [-o output_file] [input_file]\n";

	while ((c = getopt(argc, argv, "s:r:fvo:")) != -1)
		switch (c)
		{
			case 's':
				sflag = 1;
				scale = atoi(optarg);
				break;

			case 'r':
				rflag = 1;
				degree = atoi(optarg);
				break;

			case 'f':
				fflag = 1;
				break;

			case 'v':
				vflag = 1;
				break;

			case 'o':
				oflag = 1;
				output_file = optarg;
				break;

			case '?':
				err =1;
				break;

		}

	if (argv[optind])
	{
		char *input_file = argv[optind];
		readFile(input_file, &rows, &columns, &b);
	}

	else
	{
		readFile(NULL, &rows, &columns, &b);
	}

	if (sflag)
  	{
		if (scale > 0)
		{
	     	enlarge(b, rows, columns, scale, &nb, &newRows, &newColumns);
	     	rows = newRows;
	     	columns = newColumns;
			update = 1;
		}

		else
		{
	     	fprintf(stderr, "%s: Scale is not a positive integer\n", argv[0]);
	     	fprintf(stderr, usage, argv[0]);
	     	return -1;
		}

  	}

	if (rflag)
  	{
		if ((degree % 90 == 0) && degree != 0)
		{
			if (update)
			{
				rotate(nb, rows, columns, degree, &nb, &newRows, &newColumns);
		     	rows = newRows;
		     	columns = newColumns;
			}

			else
			{
				rotate(b, rows, columns, degree, &nb, &newRows, &newColumns);
		     	rows = newRows;
		     	columns = newColumns;
				update = 1;
			}
		}

		else
		{
	     	fprintf(stderr, "%s: Rotation not a multiple of 90 degrees\n", argv[0]);
	     	fprintf(stderr, usage, argv[0]);
	     	return -1;
		}
  	}

  if (vflag)
  {
	  if(update)
	  {
		  verticalflip(nb, &nb, rows, columns);
	  }

	  else
	  {
		   verticalflip(b, &nb, rows, columns);
		   update = 1;
	   }
  }

  if (fflag)
  {
	  if(update)
	  {
		  flip(nb, &nb, rows, columns);
	  }

	  else
	  {
		  flip(b, &nb, rows, columns);
	  }
  }

  if (oflag)
  {
	  writeFile(output_file, rows, columns, nb);
  }

	free(b);
	free(nb);

	return 0;
}
