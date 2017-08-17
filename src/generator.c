/*
 * Copyright 2017 Alexandre Terrasa <alexandre@moz-code.org>.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * This program generates random pandemic grids for testing purpose.
 */

#include <time.h>
#include<stdlib.h>
#include<stdio.h>

static const char DEAD = '.';
static const char HEALTHY = 'H';
static const char INFECTED = 'X';

/*
 * Prints the program usage in steout.
 */
void print_usage()
{
	fprintf(stdout, "Usage: generator <lines> <columns>\n");
}

/*
 * Generates and returns a random cell.
 *
 * Probabilities:
 * * 20% of HEALTHY
 * * 20% of INFECTED
 * * 60% of DEAD
 *
 * @return: the cell char
 */
char gen_cell()
{
	int r = rand() % 100;
	if(r > 80) {
		return HEALTHY;
	} else if(r > 60) {
		return INFECTED;
	}
	return DEAD;
}

/*
 * Generates and prints a random grid of `height` * `width` in stdout.
 *
 * @param height: number of lines in the grid
 * @param width: number of columns in the grid
 */
void gen_grid(int height, int width)
{
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			char cell = gen_cell();
			printf("%c", cell);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int height, width;
	time_t t;

	if(argc != 3) {
		fprintf(stderr, "Error: two arguments respectively the lines and columns of the grid.\n");
		print_usage();
		exit(1);
	}

	height = atoi(argv[1]);
	width = atoi(argv[2]);
	if(height < 0 || width < 0) {
		fprintf(stderr, "Error: the number of lines and columns must be positive.\n");
		print_usage();
		exit(1);
	}

	srand((unsigned) time(&t));
	gen_grid(height, width);

	return 0;
}
