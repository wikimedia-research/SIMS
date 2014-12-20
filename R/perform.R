perform <- function(sessions){
  
  #Geometric mean
  gm_mean <- function(x){
    return(exp(sum(log(x[x > 0]))/length(x)))
  }
  
  #Split and grab intertimes
  intertimes <- lapply(sessions,extract_intertimes)
  
  #Get all but the last intertime
  set1 <- all_but_last(intertimes)
  
  #Get the actual last intertimes
  set2 <- last_only(intertimes)
  
  #Construct output object!
  results <-   data.frame(variable = c("geometric mean","arithmetic mean"),
                          calculated_value = c(gm_mean(set1),mean(set1)),
                          actual_value = c(gm_mean(set2), mean(set2)),
                          stringsAsFactors = FALSE)
  results$difference <- abs((results$calculated_value - results$actual_value)/results$actual_value)*100
  
#variable calculated_value actual_value  difference
#geometric mean     46.5443     60.17764   22.65516
#arithmetic mean    253.7420    323.92493  21.66643
}