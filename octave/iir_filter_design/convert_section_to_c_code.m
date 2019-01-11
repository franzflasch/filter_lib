printf('\nInclude the following code in your C program to use the filter:\n\n')

printf('#define FILTER_INPUT_GAIN %5.16f\n\n', g)

printf('filter_sos_section_coeffs_t Bs[] = { \n') 
for row_idx = 1:rows 
	printf('{ '); 
	for col_idx = 1:cols
		if(col_idx == cols) 
			printf('%5.16f ', Bs(row_idx,col_idx)) 
		else
			printf('%5.16f, ', Bs(row_idx,col_idx)) 
		endif
	end;
	if(row_idx == rows) 
		printf('}\n'); 		
	else
		printf('},\n'); 
	endif
end;
printf('};\n\n'); 

printf('filter_sos_section_coeffs_t As[] = { \n') 
for row_idx = 1:rows 
	printf(' {'); 
	for col_idx = 1:cols
		if(col_idx == cols) 
			printf('%5.16f ', As(row_idx,col_idx)) 
		else
			printf('%5.16f, ', As(row_idx,col_idx)) 
		endif
	end;
	if(row_idx == rows) 
		printf('}\n'); 		
	else
		printf('},\n'); 
	endif
end;
printf('};\n'); 
