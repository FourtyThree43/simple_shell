char **tmp = NULL;
unsigned int i, j = 1;

if (line[nread - 2] == 92)
{
	printf("> ");
	tmp = malloc(sizeof(tmp));
	//check for malloc failure
	tmp[0] = malloc(nread);
	//check for malloc failure
	strcpy(tmp[0], line);
	
	for (i = 0, j = 1; ((nread = getline(&line, &len, stdin)) != -1) && (line[nread - 2] == 92); i++, j++)
	{
		tmp = realloc(tmp, j + 1);
		//check for malloc failure
		tmp[j] = malloc(nread);
		//check for malloc failure
	}
	tmp[j] = NULL;
	for (j = 0; tmp[j]; j++)
	{
		fwrite(tmp[j], 1, strlen(tmp[j]), stdout);
		printf("> ");
	}
	continue;
}
