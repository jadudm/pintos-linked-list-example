#include <list.h>
#include <stdio.h>
#include <stdlib.h>

/* Read the docs for how to create a list of 
   structures using this code. */
struct birthdate {
	struct list_elem elem;
	int year;
	int month;
	int day;
};

int main () {
	struct list_elem *e;
	struct list birthdate_list;

	printf ("Hi.\n");

	/* Init the list. */	
	list_init (&birthdate_list);
	
	/* Add an element or two. */

	/* Allocate space for the struct */
	struct birthdate *b = (struct birthdate *) malloc (sizeof (struct birthdate));

	/* Fill it. */
	(*b).year  = 1990;
	(*b).month = 3;
	(*b).day   = 14;
		
	/* Push the element onto the front of the list */
	list_push_front (&birthdate_list, &b->elem);

	/* Allocate space for another structure. */
	b = (struct birthdate *) malloc (sizeof (struct birthdate));

	/* Fill it. */
	b->year  = 1994;
	b->month = 12;
	b->day   = 25;

	/* Push one to the back */
	list_push_back (&birthdate_list, &b->elem);

	/* Iterate through, and print things. There's more than one way
		 to iterate through the list. Read the code. */
	for (	e = list_begin (&birthdate_list) ;
			 	e != list_end (&birthdate_list) ;
			 	e = list_next(e)) {
	
		b = list_entry (e, struct birthdate, elem);
		printf ("Year: %d\n", b->year);
	}

	printf ("Bye!\n");
	return 0;
	
}
