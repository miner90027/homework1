/* Aleks McCormick
 * UAF CS 202
 * Homework 1
 * 01/28/2021
 */

char* strdup(const char*);
char* findx(const char* s, const char* x);

int main(){

	const char *cstr = "How many chars are on the screen";
	auto temp = strdup(cstr);

	temp = findx(cstr, "char");

}

char* strdup(const char* orig){
	int size = 0;

	do
	{
		size++;
	}
	while (orig[size]);

	char *copy;
	copy = new char[size];

	for(int i = 0; i <= size;i++)
		copy[i] = orig[i];

	return copy;
}

char* findx(const char* s, const char* x){
	int sizeS = 0;
	int sizeX = 0;

	while(s[sizeS])
		sizeS++;

	while(x[sizeX])
		sizeX++;

	int j;
	for(int i = 0; i < sizeS;i++)
	{
		if(s[i] == x[0])
		{
			for(j = 0; j<sizeX;j++)
			{
				if(s[i +j] != x[j])
				{
					break;
				}
			}

			if(j==sizeX)
			{
				return (char *)&s[i];
			}
		}
	}

	return '\0';
}