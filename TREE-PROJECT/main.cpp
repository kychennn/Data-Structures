/*******************************************************************/
/* Programmer: Jiayi Chen                                          */         
/* Date: May 10, 2021                                              */          
/* Purpose: Read a report ( running text ) and issues warnings     */
/*          on style and partially correct bad style               */
/* Input: • From the keyboard:                                     */
/*        The name of the file containing the text to be analyzed  */
/*        • From the file:                                         */
/*        The report to be analyzed                                */  
/* Output: Write the following information to a file:              */
/*         • The name of the input file                            */
/*         • The statistical summary of the report                 */
/*         • The style warnings                                    */
/*******************************************************************/

#include "BSTree.cpp"

int main() 
{ 
  BSTree<string> wordTree;

  string word;
  // Open file for reading
  ifstream infile;
  // Open file for writing
  ofstream outfile;
  
  string inputFile;
  
  // Ask the user input the file name
  cout<<"Please enter the file name: "<<endl;
  cin>>inputFile;

  infile.open(inputFile, ios::in);

  while (!infile.is_open())
  {
    cout << "\nERROR - THE FILE CAN NOT BE OPENED. Please try again.\n";
    cin >> inputFile;
    cout << endl << endl;
    infile.open(inputFile);
  }

  while (!infile.eof())
  {
    infile >> word;
    for( int i = 0; i < word.length(); i++ )
    {
      if (isupper(word[i]))
      {
        word[i] = word[i] + 32; 
      }
    }
    wordTree.sentenceCounter(word);
    wordTree.wordCounter(word);
    wordTree.charCounter(word);
    wordTree.insertItem(word);
  }

  infile.close();

  outfile.open("Analysis Report.txt");
	outfile << "FILE NAME: " << inputFile << endl;
	outfile << "\n[STATISTICAL SUMMARY]";
	outfile << "\n\nTOTAL NUMBER OF WORDS: " << wordTree.getTotalWords() << endl;
	outfile << "\nTOTAL NUMBER OF \"UNIQUE\" WORDS: " << wordTree.getTotalUniqueWords() << endl;
	outfile << "\nTOTAL NUMBER OF \"UNIQUE\" WORDS OF MORE THAN THREE LETTERS: " << wordTree.getTotalUWMoreThanThree() << endl;
	outfile << "\nAVERAGE WORD LENGTH: " << wordTree.getAvgWordLength() << " characters" << endl;
	outfile << "\nAVERAGE SENTENCE LENGTH: " << wordTree.getAvgSentenceLength() << " words\n\n\n";
	outfile << "[STYLE WARNINGS]\n";
	outfile << "\nWORDS USED TOO OFTEN: (WORDS OF MORE THAN 3 LETTERS THAT ARE USED MORE THAN 5% OF THE TOTAL NUMBER OF WORDS OF MORE THAN 3 LETTERS)\n";
  wordTree.printOftenWords(outfile);
  if ( wordTree.getAvgSentenceLength() > 10) {
		outfile << "\n\nAVERAGE SENTENCE LENGTH TOO LONG - " << wordTree.getAvgSentenceLength() << " words\n";
	}
  if ( wordTree.getAvgWordLength() > 5) {
		outfile << "\nAVERAGE WORD LENGTH TOO LONG - " << wordTree.getAvgWordLength() << " characters\n";
	}
  outfile << "\n\n[INDEX OF UNIQUE WORDS]";
  wordTree.printIndex(outfile);
	outfile.close();

  cout<<"\n**** THE ANALYSIS REPORT IS PREPARED ****\n";
  
  return 0;
}