/*Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems. 
  It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').

  Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly from DNA its 
  chemical structure and contains no Thymine. In RNA Thymine is replaced by another nucleic acid Uracil ('U').

  Create a function which translates a given DNA string into RNA.*/

#include <string>

std::string DNAtoRNA(std::string dna){
  //making a copy for legibility|a more direct solutioin listed below. 
  std::string rna="";
  for (int x=0;x<dna.size();x++){
    
    if(dna[x]=='T')
      rna+="U";
    
    else
      rna+=dna[x];
  }
  return rna;
}

//A more direct solution.
std::string DNAtoRNA(std::string dna){
  //iterartes over the entire string, replacing T with U and returning the result.
  std::replace(dna.begin(),dna.end(), 'T', 'U');
  return dna;
}
