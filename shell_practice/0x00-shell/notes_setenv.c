
/* notes */
/*
	- use _getenv() to check if name exists in the environment
		- if it does, check if overwrite is non zero.
			- if `overwrite` == 0, return 0 (success).
			- otherwise, change the relevant string. Parse the list using a temp pointer to locate the appropriate node.
		- if it does not (i.e NULL is returned):
			- Add a node at the end of the list.
			- Initialise the first member with `value` and the second with NULL.

*/
