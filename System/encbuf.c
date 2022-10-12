char salt = '#';

int Transform(char bytes[], int count)
{
	register int i;

	for(i = 0; i < count; ++i)
	{
		bytes[i] ^= salt;
	}

	return count;
}

/*
	Only an object module containing position-independent code (which does
	not use direct addressing) can be included in a shared-object because
	such a module can be mapped at any location within its dependent process.
	Any C source code in which a global function refers to a global symbol
	must be compiled with -fPIC to force generation of position-indepent
	code within the object module
*/

