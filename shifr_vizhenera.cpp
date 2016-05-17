#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
string get_key(string key, string text);
string vizhenere(string alphabet, string text, string new_key, string shifr, int h);
string readtextf(string tname);
string readkeyf(string kname);
string deshifr_key (string new_key, string alphabet);

int main(int argc, char *argv[])
{
	string text, key, new_key,shifr = "";
	string alphabet = "abcdefghijklmnopqrstvuwxyz";
	string kname, tname = "";
	

	int cmd = 0;
	int h;
	while((cmd = getopt(argc, argv, "t:k:ed")) != -1)
	{
		switch(cmd)
		{
			case 't':
				tname = optarg;
				text = readtextf(tname);
				break;
			case 'k':
				kname = optarg;
				key = readkeyf(kname);
				break;
			case 'e':
				h = 1;
				break;
			case 'd':
				h = 0;
				break; 

		}
	}
	new_key = get_key(key, text);
	if (h == 1)
	{	
		vizhenere(alphabet, text, new_key, shifr, h);
	}
	else
	{
		new_key = deshifr_key(new_key, alphabet);
		vizhenere(alphabet, text, new_key, shifr, h);
	}
	getchar();
	return 0;
}
string readtextf(string tname)
{
	string t = "";
	ifstream infile;
	infile.open(tname.c_str());

	if (!infile.is_open())
	{
		cout << "Error!" << endl;
		getchar();
		return 0;
	}
	infile >> t;
	cout << "Text: " << t << endl;
	infile.close();
	return t;
}
string readkeyf(string kname)
{
	string k = "";
	ifstream infile;
	infile.open(kname.c_str());
	if (!infile.is_open())
	{
		cout << "Error!" << endl;
		getchar();
		return 0;
	}
	infile >> k;
	cout << "Key: " << k << endl;
	infile.close();
	return k;
}
string get_key(string key, string text)
{
	string nk = "";
	if (text.size() >= key.size())
	{
		for (int i = 0;i < (text.size() / key.size()); i++)
		{
			nk = nk + key;
		}
			for (int j = 0;j < (text.size() % key.size()); j++)
			{
				nk = nk + key[j];
			}
	}
	else
	{
		for (int s = 0;s < text.size();s++)
		{
			nk = nk + text[s];
		}

	}
	
	cout << "New key: " << nk << endl;
	return nk;
}

string deshifr_key(string new_key, string alphabet)
{
	string mass_key;
	for (int k = 0; k < new_key.size();k++)
	{
		for (int n = 0; n < alphabet.size();n++)
		{
				if (new_key[k] == alphabet[n])
				mass_key[k] = 26 - n;
		}
	}
	
			for (int i = 0; i < new_key.size() ;i++)
			{
				new_key[i] = alphabet[mass_key[i]];	
			}


	cout << "Key for deshifr: "<< new_key << endl;
	return new_key;
}

string vizhenere(string alphabet, string text, string new_key, string shifr, int h)
{
	int x;
	int y;
	for (int k = 0; k < text.size();k++)
	{
		x = -1;
		y = -1;
		for (int n = 0; n < alphabet.size();n++)
		{
			if (text[k] == alphabet[n])

				x = n;

			if (new_key[k] == alphabet[n])

				y = n;
		}
		if (x != -1 && y != -1)
			shifr = (shifr + (alphabet[(x + y) % 26]));
		else
			shifr = shifr + text[k];
		
		}
			if(h==1)
				cout << "Encrypted text: " << shifr << endl;
			
				if(h==0)
					cout << "Decrypted text: " << shifr << endl;				
			
	return shifr;
}	

