#include <Rcpp.h>
using namespace Rcpp;

// Generate intertimes
// [[Rcpp::export]]
std::vector < int > extract_intertimes(std::vector < int > sessions){
   
   //Declare output, iterator
  std::vector < int > output;
  std::vector < int > out_holding;
  
  int in_size = sessions.size();
  if(in_size >= 2){
    std::sort(sessions.begin(),sessions.end());
    for(int i = 1; i < in_size; i++){
      output.push_back(sessions[i] - sessions[i-1]);
    }
  }
  
  return output;
}

//Extract all-but-last
// [[Rcpp::export]]
std::vector < int > all_but_last(std::list < std::vector < int > > sessions){
   
   //Declare output, iterator
  std::list < std::vector < int > >::const_iterator iterator;
  std::vector < int > in_holding;
  std::vector < int > output;
  
  //For each list entry, extract all-but-the-last intertime - excepting one-intertime sessions.
  //Always include those.
  for (iterator = sessions.begin(); iterator != sessions.end(); ++iterator){
    in_holding = *iterator;
    int in_size = in_holding.size();
    
    if(in_size >= 2){
      for(int i = 1; i < in_size-1; i++){
        output.push_back(in_holding[i]);
      }
    } else {
      output.push_back(in_holding[0]);
    }
  }
  
  return output;
}

//Extract last-only
// [[Rcpp::export]]
std::vector < int > last_only(std::list < std::vector < int > > sessions){
   
   //Declare output, iterator
  std::list < std::vector < int > >::const_iterator iterator;
  std::vector < int > in_holding;
  std::vector < int > output;
  
  //For each list entry, extract the last value. Ignore if it has <2 intertimes.
  for (iterator = sessions.begin(); iterator != sessions.end(); ++iterator){
    in_holding = *iterator;
    int in_size = in_holding.size();
    if(in_size >= 2){
      output.push_back(in_holding[in_size-1]);
    }
  }
  
  return output;
}