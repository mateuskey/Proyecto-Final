#include <stdint.h>
//parametros para la matriz
// Matriz inicial
	printf("\nMatriz Inicial:\n");
	for(i=0; i<db.N; i++){
		for(j=0; j<db.M; j++){
			if((i == 0 && j == 0) || (i == 14 && j == 14) || (i == 14 && j == 0) || (i == 0 && j == 14) || (i == 7 && j == 7)){
				M[i][j] = 1;
			}else{
				M[i][j] = 0;
			}
			printf("%i ", M[i][j]);
		}
		printf("\n");
	}

	// fclose(Puntero_FILE)
	fclose(fr);

	int L = 0;

	printf("\nIngrese la cantidad de ciclos evolutivos: ");
	scanf("%i", &L); printf("\n");
	int x;
	for(x=0; x<L; x++){
		printf("\nCiclo evolutivo [%i]\n", x+1);


		// Esquina superior izquierda
		if( M[0][0] == 1 ){
			if( M[0][0+1] == 0 && M[0+1][0] == 0 && M[0+1][0+1] == 0 )
				push(C, 0, 0, 0);
			else if( M[0][0+1] == 0 && M[0+1][0] == 0 && M[0+1][0+1] == 1 )
				push(C, 0, 0, 0);
			else if( M[0][0+1] == 0 && M[0+1][0] == 1 && M[0+1][0+1] == 0 )
				push(C, 0, 0, 0);
			else if( M[0][0+1] == 1 && M[0+1][0] == 0 && M[0+1][0+1] == 1 )
				push(C, 0, 0, 0);
		}else if(M[0][0] == 0){
			if( M[0][0+1] == 1 && M[0+1][0] == 1 && M[0+1][0+1] == 1 )
				push(C, 1, 0, 0);
		}

		// Esquina inferior izquierda
		if( M[db.N-1][0] == 1 ){
			if( M[db.N-2][0] == 0 && M[db.N-2][0+1] == 0 && M[db.N-1][0+1] == 0 )
				 push(C, 0, db.N-1, 0);
			else if( M[db.N-2][0] == 0 && M[db.N-2][0+1] == 0 && M[db.N-1][0+1] == 1 )
				 push(C, 0, db.N-1, 0);
			else if( M[db.N-2][0] == 0 && M[db.N-2][0+1] == 1 && M[db.N-1][0+1] == 0 )
				 push(C, 0, db.N-1, 0);
			else if( M[db.N-2][0] == 1 && M[db.N-2][0+1] == 0 && M[db.N-1][0+1] == 1 )
				 push(C, 0, db.N-1, 0);
		}else if(M[db.N-1][0] == 0){
			if( M[db.N-2][0] == 1 && M[db.N-2][0+1] == 1 && M[db.N-1][0+1] == 1 )
				 push(C, 1, db.N-1, 0);
		}

		// Esquina superior derecha
		if( M[0][db.M-1] == 1 ){
			if( M[0][db.M-2] == 0 && M[0+1][db.M-2] == 0 && M[0+1][db.M-1] == 0 )
				 push(C, 0, 0, db.M-1);
			else if( M[0][db.M-2] == 0 && M[0+1][db.M-2] == 0 && M[0+1][db.M-1] == 1 )
				 push(C, 0, 0, db.M-1);
			else if( M[0][db.M-2] == 0 && M[0+1][db.M-2] == 1 && M[0+1][db.M-1] == 0 )
				 push(C, 0, 0, db.M-1);
			else if( M[0][db.M-2] == 1 && M[0+1][db.M-2] == 0 && M[0+1][db.M-1] == 1 )
				 push(C, 0, 0, db.M-1);
		}else if(M[0][db.M-1]){
			if( M[0][db.M-2] == 1 && M[0+1][db.M-2] == 1 && M[0+1][db.M-1] == 1 )
				 push(C, 1, 0, db.M-1);
		}

		// Esquina inferior derecha
		if( M[db.N-1][db.M-1] == 1 ){
			if( M[db.N-1][db.M-2] == 0 && M[db.N-2][db.M-2] == 0 && M[db.N-2][db.M-1] == 0 )
				 push(C, 0, db.N-1, db.M-1);
			else if( M[db.N-1][db.M-2] == 0 && M[db.N-2][db.M-2] == 0 && M[db.N-2][db.M-1] == 1 )
				 push(C, 0, db.N-1, db.M-1);
			else if( M[db.N-1][db.M-2] == 0 && M[db.N-2][db.M-2] == 1 && M[db.N-2][db.M-1] == 0 )
				 push(C, 0, db.N-1, db.M-1);
			else if( M[db.N-1][db.M-2] == 1 && M[db.N-2][db.M-2] == 0 && M[db.N-2][db.M-1] == 1 )
				 push(C, 0, db.N-1, db.M-1);
		}else if(M[db.N-1][db.M-1]){
			if( M[db.N-1][db.M-2] == 1 && M[db.N-2][db.M-2] == 1 && M[db.N-2][db.M-1] == 1 )
				 push(C, 1, db.N-1, db.M-1);
		}

		////////////////////////
		// Borde izquierdo
		for(i=1; i<db.N-1; i++){

			// Viendo si nace
			if( M[i][0] == 0 ){
				cont_v=0;

				if( M[i-1][0] == 1 )
					cont_v++;

				if( M[i-1][0+1] == 1 )
					cont_v++;

				if( M[i][0+1] == 1 )
					cont_v++;

				if( M[i+1][0+1] == 1 )
					cont_v++;

			 	if( M[i+1][0+1] == 1 )
					cont_v++;

				// Verificador de si nace o no
				if( cont_v == 3 )
					push(C, 1, i, j);

			// Viendo si muere
			}else if( M[i][0] == 1 ){
				cont_v=0;

				if( M[i-1][0] == 1 )
					cont_v++;
				if( M[i-1][0+1] == 1 )
					cont_v++;
				if( M[i][0+1] == 1 )
					cont_v++;
				if( M[i+1][0+1] == 1 )
					cont_v++;
				if( M[i+1][0+1] == 1 )
					cont_v++;

				// verificador si muere
				if( cont_v < 2 || cont_v > 3 )
					push(C, 0, i, j);
			}
		}


		///////////////////
		// borde derecho
		for(i=1; i<db.N-1; i++){

			// Viendo si nace
			if( M[i][db.M-1] == 0 ){
				cont_v=0;

				if( M[i-1][db.M-1] == 1 )
					cont_v++;

				if( M[i-1][db.M-2] == 1 )
					cont_v++;

				if( M[i][db.M-2] == 1 )
					cont_v++;

				if( M[i+1][db.M-2] == 1 )
					cont_v++;

			 	if( M[i+1][db.M-1] == 1 )
					cont_v++;

				// Verificador de si nace o no
				if( cont_v == 3 )
					 push(C, 1, i, db.M-1);

			// Viendo si muere
			}else if(  M[i][db.M-1] == 1 ){
				cont_v=0;

				if( M[i-1][db.M-1] == 1 )
					cont_v++;
				if( M[i-1][db.M-2] == 1 )
					cont_v++;
				if( M[i][db.M-2] == 1 )
					cont_v++;
				if( M[i+1][db.M-2] == 1 )
					cont_v++;
				if( M[i+1][db.M-1] == 1 )
					cont_v++;

				// verificador si muere
				if( cont_v < 2 || cont_v > 3 )
					 push(C, 0, i, db.M-1);
			}
		}


		//////////////////
		// borde superior
		for(j=1; j<db.M-1; j++){

			// Viendo si nace
			if( M[0][j] == 0 ){
				cont_v=0;

				if( M[0][j-1] == 1 )
					cont_v++;

				if( M[0+1][j-1] == 1 )
					cont_v++;

				if( M[0+1][j] == 1 )
					cont_v++;

				if( M[0+1][j+1] == 1 )
					cont_v++;

			 	if( M[0][j+1] == 1 )
					cont_v++;

				// Verificador de si nace o no
				if( cont_v == 3 )
					 push(C, 1, i, db.M-1);

			// Viendo si muere
			}else if( M[0][j] == 1 ){
				cont_v=0;

				if( M[0][j-1] == 1 )
					cont_v++;
				if( M[0+1][j-1] == 1 )
					cont_v++;
				if( M[0+1][j] == 1 )
					cont_v++;
				if( M[0+1][j+1] == 1 )
					cont_v++;
				if( M[0][j+1] == 1 )
					cont_v++;

				// verificador si muere
				if( cont_v < 2 || cont_v > 3 )
					 push(C, 0, i, db.M-1);
			}
		}


		/////////////////////
		// borde inferior
		for(j=1; j<db.M-1; j++){

			// Viendo si nace
			if( M[db.N-1][j] == 0 ){
				cont_v=0;

				if( M[db.N-1][j-1] == 1 )
					cont_v++;

				if( M[db.N-2][j-1] == 1 )
					cont_v++;

				if( M[db.N-2][j] == 1 )
					cont_v++;

				if( M[db.N-2][j+1] == 1 )
					cont_v++;

			 	if( M[db.N-1][j+1] == 1 )
					cont_v++;

				// Verificador de si nace o no
				if( cont_v == 3 )
					 push(C, 1, db.N-1, j);

			// Viendo si muere
			}else if( M[0][j] == 1 ){
				cont_v=0;

				if( M[db.N-1][j-1] == 1 )
					cont_v++;
				if( M[db.N-2][j-1] == 1 )
					cont_v++;
				if( M[db.N-2][j] == 1 )
					cont_v++;
				if( M[db.N-2][j+1] == 1 )
					cont_v++;
				if( M[db.N-1][j+1] == 1 )
					cont_v++;

				// verificador si muere
				if( cont_v < 2 || cont_v > 3 )
					push(C, 0, db.N-1, j);
			}
		}



		/////////////////
		// centro
		for(i=1; i<db.N-1; i++){
			for(j=1; j<db.M-1; j++){

				// viendo si nace
				if(M[i][j] == 0){
					cont_v = 0;

					if( M[i-1][j-1] == 1 )
    		    		cont_v++;
    		  		if( M[i-1][j] == 1 )
    		    		cont_v++;
    		  		if( M[i-1][j+1] == 1 )
    		    		cont_v++;
    		  		if( M[i][j-1] == 1 )
    		    		cont_v++;
    		  		if( M[i][j+1] == 1 )
    		    		cont_v++;
    		  		if( M[i+1][j-1] == 1 )
    		    		cont_v++;
    		  		if( M[i+1][j] == 1 )
    		    		cont_v++;
    		  		if( M[i+1][j+1] == 1 )
    		    		cont_v++;


					if( cont_v == 3 )
						push(C, 1, i, j);

				// viendo si muere
				}else if( M[i][j] == 1 ){

					if( M[i-1][j-1] == 1 )
    		    		cont_v++;
    		  		if( M[i-1][j] == 1 )
    		    		cont_v++;
    		  		if( M[i-1][j+1] == 1 )
    		    		cont_v++;
    		  		if( M[i][j-1] == 1 )
    		    		cont_v++;
    		  		if( M[i][j+1] == 1 )
    		    		cont_v++;
    		  		if( M[i+1][j-1] == 1 )
    		    		cont_v++;
    		  		if( M[i+1][j] == 1 )
    		    		cont_v++;
    		  		if( M[i+1][j+1] == 1 )
    		    		cont_v++;


					if( cont_v < 2 || cont_v > 3 )
						 push(C, 0, i, j);
				}
			}
		}
