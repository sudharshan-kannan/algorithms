//
// Author           : skannan
// Timestamp        : 8/14/21, 5:49 PM
// Compile command  : g++ -Wall -o exec whitelist.cpp -I ~/CLionProjects/algorithms-and-data-structures/include
// Description      : Whitelist integer values using binary search algorithm
//



/* Desc         : Filter integers that are not in the whitelist file and dump the info to specified file
 * Input        : file names of whitelist integers, input integers to query, file to dump the filtered list
 * Output       : Check dumped file to see filtered list of integers and the sorted index where the element was found
*/
#include "../include/driver.h"

void whitelist_ints(const std::string &whitelist_file, const std::string &infile, const std::string &outfile){
    std::ifstream whitelist_stream(whitelist_file);
    if(!whitelist_stream.is_open())
        throw(std::runtime_error("Error opening whitelist file."));

    std::ifstream sought_stream(infile);
    if(!sought_stream.is_open())
        throw(std::runtime_error("Error opening sought file"));

    std::ofstream output_stream(outfile, std::ofstream::app);
    if(!output_stream.is_open())
        throw(std::runtime_error("Error opening output file"));

    std::istream_iterator<int> whitelist_reader(whitelist_stream), sought_reader(sought_stream), eof;

    std::vector<int>  whitelist(whitelist_reader, eof);
    std::vector<int>  soughtlist(sought_reader, eof);

    /* Sort the container before using binary search */
    std::sort(whitelist.begin(), whitelist.end());

    for(const auto &s : soughtlist) {
        //int found = GenericAlgorithms::binary_search_naive(whitelist, s);
        int found = GenericAlgorithms::binary_search_recursion(whitelist.begin(), whitelist.end(), s);
        if(found < 0)
            output_stream << s << " not found." << std::endl;
        else
            output_stream << s << " found at index " << found << " in sorted order. " << std::endl;
    }
}
