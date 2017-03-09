#include <iostream>
#include <fstream>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

const std::string outfile = "output.txt"; // output file name

using namespace std;

//--- PART 1A: Implementation and testing of heap insert
/* 
* Tests insert() and swap_up() function for max_heap class.
* Outputs results to outfile.   
* Params: &hp - reference to a max_heap
*/
void heap_insert_tests(max_heap &hp) {
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file	
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);

	//--- Testing insert functionality
  output << "BEGINNING TESTS FOR PART 1A" << "\n";
	output << "*** TESTING INSERT ***" << "\n";
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		output << "Adding " << text << ",  with number " << random_num << " to heap" 
      << "\n";
		hp.insert(text_item{text, random_num});
		temp = hp.top();
		output << "Top of heap is: " << temp << "\n";		
	}
	//--- CUSTOM TESTS 
	// testing insert without any swap_ups needed
  int to_insert = -1;
	word = "insert_test_";  
  // loop to insert text with freq of -1, 0, 1, 2
  for(int i = 0; i < 4; i++){ 
    string text = word;
    text += std::to_string(to_insert);
    output << "adding " << text << ",  with number " << to_insert << " to heap"  
      << "\n";
    hp.insert(text_item{text, to_insert});
    temp = hp.top();
	  output << "Top of heap is: " << temp << "\n";
    to_insert++;
  }

	// testing insert with swap_ups
  int to_swap = 10;
	word = "swap_up_test_";  
  // loop to insert text with freq of 10, 110, 210, 310, 410
  for(int i = 0; i < 5; i++){ 
    string text = word;
    text += std::to_string(to_swap);
    output << "adding " << text << ",  with number " << to_swap << " to heap" << "\n";
    hp.insert(text_item{text, to_swap});
    temp = hp.top();
	  output << "Top of heap is: " << temp << "\n";
    to_swap += 100;
  }
  output << "\n";
  output.close(); // closing output file
}


//--- PART 1B: Implementation and testing of heap delete
/* 
* Tests delete_max() and swap_down() function for max_heap class. 
* Outputs results to outfile. 
* Params: &hp - reference to a max_heap
*/
void heap_delete_tests(max_heap &hp) {
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file	
	text_item temp;
	//--- Testing deleteMax functionality
  output << "BEGINNING TESTS FOR PART 1B" << "\n";
	output << "*** TESTING DELETEMAX ***" << "\n";
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) { 
		temp = hp.delete_max();
		output << "Item returned from heap delete: "<< temp << "\n";
		temp = hp.top();
		output << "Top of heap is now: " << temp << "\n";	
	}

	//--- CUSTOM TESTS
  // deleting all current elements in heap
  output << "Deleting all elements in heap" << "\n";
  while(hp.size() > 0){
    temp = hp.delete_max();
	  output << "Item returned from heap delete: "<< temp << "\n";
  }
  // starting custom testing w/ new heap with 4 elements (freqs of -1, 0, 1, 2)
  output << "Inserting elements with freqs of -1,0,1,2" << "\n";
  for(int i = -1; i < 3; i++){
    string text = "delete_test_";
    text += std::to_string(i);
    hp.insert(text_item{text,i}); 
    temp = hp.top();
	  output << "Top of heap is now: " << temp << "\n";
  }
	// remove_max works when swap_down with left child
	output << "Left child of heap should be 1. Top should be 2." << "\n";
  temp = hp.delete_max();
	output << "Item returned from heap delete: "<< temp << "\n";
  output << "Top of heap should now be 1" << "\n";
  temp = hp.top();
	output << "Top of heap is now: " << temp << "\n";
		
	// remove_max works when swap_down with right child
	output << "Right child of heap should be 0." << "\n";
  temp = hp.delete_max();
	output << "Item returned from heap delete: "<< temp << "\n";
  output << "Top of heap should now be 0" << "\n";
  temp = hp.top();
	output << "Top of heap is now: " << temp << "\n";
		
	// remove_max on an empty heap (should throw exception similar to top())
  output << "Emptying heap..." << "\n";
  while(hp.size() > 0){
    temp = hp.delete_max();
	  output << "Item returned from heap delete: "<< temp << "\n";
  }
	try{
    output << "Attempting to delete from empty heap." << "\n";
    hp.delete_max();
  } catch (std::logic_error e){
    output << e.what() << "\n";
  }
  output << "\n";
  output.close(); // closing output file
}


//--- PART 2: Implementation and testing of BST word_frequency

/* 
* Tests string_bst.word_frequency() function for string_bst class.  
* Outputs results to outfile.
* Params: const &tree - constant reference of a string_bst
*/
void tree_tester(string_bst const &tree) {
  std::ofstream output;
  output.open (outfile, ios::app); // if exists, appends to end of current file
	output << "BEGINNING TESTS FOR PART 2" << "\n";
	//--- Testing word_frequency functionality
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
	}
	
	//--- CUSTOM TESTS
  // test customized for sample1.txt 
    // tree.display();
  // test that can search through left and right subtrees  
  if (tree.size() > 1) {
    int num_times = 0;
    string to_find;
		to_find = "a"; // "a" is in left most subtree
		num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
    to_find = "writing"; // "writing" is in right most subtree
		num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
    to_find = "word"; // "word" is in a right subtree
		num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
    to_find = "calculate"; // "calculate" is in a left subtree
		num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
 
  	// test that it returns 0 if word is not found
    to_find = "xyz";
		num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
    to_find = "";		
    num_times = tree.word_frequency(to_find);
		output << "Found: empty string in the input file " 
      << num_times << " time(s)." << "\n";
		to_find = "&xyz";
		num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
    to_find = "1234555";
	  num_times = tree.word_frequency(to_find);
		output << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << "\n";
	}
  output << "\n";
  output.close();
}


//--- PART 3: Implementation and testing of word frequency analysis

/* 
* Outputs top 5 most frequent words to outfile. If there is a tie for 
* word frequency, function outputs words sorted alphabetically up to a
* max of 5 words total. 
* Params: hp - copy of a max_heap
*/
void overall_most_freq(max_heap hp) {
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file
	output << "*** Top 5 most frequent words: ***" << "\n";
  int count = 0;
	while (hp.size() > 0 && count < 5) {
		output << hp.delete_max() << "\n";
    count++;
	}
  output << "\n";
  output.close();
}

/* 
* Outputs 5 most common words of length at least <num_letters> to outfile.
* If there is a tie for word frequency, function outputs words sorted
* alphabetically up to a max of 5 words total.
* Params: hp - copy of a max_heap 
*         num_letters - minimum length of words to output
*/
void at_least_length(max_heap hp, size_t num_letters) {
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file	
  output << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << "\n";
  int count = 0;
  while (hp.size() > 0 && count < 5) {
    text_item max = hp.delete_max();
    size_t length = max.word.length();
    if(length >= num_letters){
      output << max << "\n";    
      count++;    
    }	
  }
  output << "\n";
  output.close();
}

/* 
* Outputs the 5 most common words starting with <starts_with_letter> to outfile.
* If there is a tie for word frequency, function outputs words sorted
* alphabetically up to a max of 5 words total.
* Params: hp - copy of a max_heap 
*         starts_with_letter - char of starting letter
*/
void starts_with(max_heap hp, char starts_with_letter) {
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file	
	output << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << "\n";
	int count = 0;
  while (hp.size() > 0 && count < 5) {
    text_item max = hp.delete_max();
    if(max.word.at(0) == starts_with_letter){
      output << max << "\n";    
      count++;    
    }	
  }
  output << "\n";
  output.close();	
}

/*
*	Method to test heap_insert_tests() and heap_delete_tests()
* in max_heap class
*/
void heap_tester() {	
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file	

	text_item temp;
	int heap_size = 15; // feel free to create heaps of other sizes when testing
	max_heap hp(heap_size);
	output << "Created heap of size " << heap_size << "\n";
		
	//--- Testing heap size and top
	output << "Current number of items in heap is: " << hp.size() << "\n";
	try {
		temp = hp.top(); //should throw an exception without items in heap
		output << "Top of heap is: " << temp << "\n";	
	} catch (std::logic_error e) {
		output << e.what() << "\n";
	}
  output.close();
	
  // PART 1A:
	heap_insert_tests(hp);
	// PART 1B:
	heap_delete_tests(hp);
}

/*
*	Method for testing overall_most_freq(), at_least_length(),
* and starts_with() functions in string_bst class
* Params: &tree - reference to a string_bst tree
*/
void text_analysis_tester(string_bst &tree) {
  std::ofstream output;
  output.open (outfile, ios::app); // if file exists, appends to end of file	
	output << "BEGINNING TESTS FOR PART 3" << "\n";
  output.close();	

	overall_most_freq(copy_to_heap(tree));
	at_least_length(copy_to_heap(tree), 8); 
  // additional tests for at_least_length
  at_least_length(copy_to_heap(tree), 6); 
  at_least_length(copy_to_heap(tree), 0); 
  at_least_length(copy_to_heap(tree), 1); 
  at_least_length(copy_to_heap(tree), 10); 
	starts_with(copy_to_heap(tree), 'c');
  // additional tests for starts_with
	starts_with(copy_to_heap(tree), 'a');
  starts_with(copy_to_heap(tree), 's');
  starts_with(copy_to_heap(tree), 'q');
  starts_with(copy_to_heap(tree), '!');
  starts_with(copy_to_heap(tree), '1');
}

int main(int argc, char* argv[]) {
  
  // removes any existing outfile so new outfile contains  
  // only results from current tests
  remove(outfile.c_str()); 

  std::cout << "Running tests... See output.txt for results" << std::endl;
	
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample1.txt", tree); // create a bst from an input file
	tree_tester(tree);		
	
	//--- Part 3: word frequency analysis of text files
  string_bst tree2;
	load_bst("sample2.txt", tree2); // create a bst from an input file
	text_analysis_tester(tree2);

}
