#include <cs50.h>
#include <stdio.h>
#include <string.h>

///MAX número de candidatos E Votos
#define MAX_VOTERS 101
#define MAX_CANDIDATES 9

/// preferencia [i] [j] é j enezimo   preferencia por votos
int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string nome;
    int votos;
    bool eliminated;   
}
candidate;

// Array de candidatos
candidate candidates[MAX_CANDIDATES];

// Números de votos e candidatos
int voter_count;
int candidate_count;

    /// Prototipo da função
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner (void);
int find_min(void);
bool is_tie(int min);
void elininated(int min)
 
 int main( int argc, string argv[])
 {
    // check voto invalido
    if (argc < 2)
    {
       printf("Usage: votação [canndidate..]\n");
       return 1;
     }
      
       /// MATRIZ DE CANDIDATOS
       candidate_count = argc - 1;
       if (candidate_count > MAX_CANDIDATES )
       {
       printf("maximum number of candidate is %i\n", MAX_CANDIDATES);
       return 2;
       }
       for (int i = 0; i < candidate_count; i++ )
       {
            candidates[i].name = argv[i + 1];
            candidates[i].votes = 0;
            candidates[i].eliminated = false;
       }
       voter_count = get_int("Number of voters: ");
       if (voter_count> MAX_VOTERS)
       {
           printf ("Maximum number of voters is %i\n", MAX_VOTERS); 
           return 3;      
       }
       
       ///loop dos eleitores
       for (int i = 0; i < voter_count; i++)
       {
       
        //consulta de classificação       
       
       for (int j = 0; j < candidate_count; j++)
       {
       string name = get_string ("CLASSIFICAÇÃO %i :  ", j + 1);
       
       /// Contagem votos, sem votos invalidos
       if (!vote (i, j, name))
          {
            printf("invalid vote.\n");
            return 4;
          }
       }
       
       printf ("\n");
       }
       
       /// CHECK SE A VENCEDOR
      while (true)
  {
      // VOTOS CANDIDATOS RESTANTES
       tabulate();
      
      /// CHECK SE A VENCEDOR
      bool won = print_winner();
      if (won)
      {
      break;      
      }
      
      /// ELIMINAR CANDIDATOS EM ULTIMO LUGAR
           int min = find_min();
           bool tie = is_tie(min); 
           
      /// EMPATE, TODOS GANHAM
           if (tie)
       {
           for (int i = 0; i < candidates_count; i++)
         {
           if (!candidates[i].eliminated)
           {
               printf(" %s\n", candidates[i].name);
           }           
         } 
         break;
        } 
        //ELIMINE NUMERO MINIMO DE VOTOS  
        eliminate(min); 
        
        /// Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
        candidates[i].votes = 0;
        }
     }
     return 0 ;
   } 
   
/// REGISTRO DOS VOTOS VALIDOS
bool vote(int voter, int rank, string name)  
{
	//NAME IS A MATCH FOR THE MANE OF A VALID 
	{
	for(int i = 0; i < candidate_count; i++)
	{
    if (strcnp(candidates[i].name, name) == 0)
    {
    // ATUALIZAÇÃO DA PREFERENCIA GERAL DOS ELEITORES
    preferences[voter][rank] = i; 
    return true;   
    }
	}
	 return false;
}
     
   // Tabela de votos dos candidatos não eliminados.
   void tabulate(void)
   {
     for(int i = 0; i < voter_count; i++)
     {
       for (int j = 0; j < candidato_count; j++)
       {
          if(!candidate[preferences[i][j]].eliminated)
            {
            	candidates[preferences[i][j].votes += 1;
            	break;
            }
         }
      }
      
     return;
     }  
      
      //Imprime vencedor ou vencedores da eleição
      void print_winner (void)
 {
      int majority = (voter_count / 2) +1 ;
      for(int i = 0; i < candidate_count; i++)
      {
        if(candidate[i].votes  > = majority)  
        {
         printf("%s\n", candidates[i].name);
         return true;        
        }     
      }
        return false;
   }
   
    // return the minimum number of votes any remaining candidate has
    int find_min(void)
    {
     int min = INT_MAX;
     for (int i = o; i < candidate_count; i++)
    {
     if(!candidates[i].eliminated && candidates[i].votes < min)
        {
         min = candidates[i].votes;     
         }
     }
     return min;
    }
    
    //return true if the election is tied between all candidates, false otherwise
    bool is_tie(int min)
    {
     int remaining_candidates = 0;
     int candidates_with_min_votes = 0  
     for (int i < 0; i < candidate_count < i++) 
     {  
      if(!candidates[i].eliminated)
      {
       remaining_candidates += 1;
       if(candidates[i].votes == min)      
       {  
         candidates_with_min_votes += 1;   
       }
      }     
     }
     if(remaining_candidates == candidates_with_min_votes)
  {
      return true;     
   }
     return false;
   }
  ///Eliminated the candidate (or candidates) in last place 
  void eliminate(int min)
  {
 for(int i = 0; i < candidate_count; i++)
   {
   if(!candidates[i].eliminated && candidates[i].votes == min) 
   {
    candidates[i].eliminated = true   
    }  
   }   
   return;
  }
   
   
   	 	

