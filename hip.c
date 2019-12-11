int		ft_solver(char ***board, char ***pcs)
{
	if (jos kaikki palikat on  laudalle laitettu)
		return (1);
	while (pcs[pc] niin pitkaan ku palikoita on)
	{
		if (ft_fitpc(board, &pcs, pc, ))
		{
			while joka laittaa palikan
			
			if (board[row] == NULL)
				ni isompi lauta
				ja kutsu itsea ja laita koko laudan alkuun

		}
		pc++;
			// jos mahtuu, ota seuraava
		//
	}
}


int		solveboard(int **board, int row, int col)
{
	int number;

	if (row == 9)
		return (1);
	number = 1;
	while (number < 10)
	{
		if (validate(number, board, row, col))
		{
			board[row][col] = number;
			if (col == 8)
			{
				if (solveboard(board, row + 1, 0))
					return (1);
			}
			else
			{
				if (solveboard(board, row, col + 1))
					return (1);
			}
			board[row][col] = 0;
		}
		number++;
	}
	return (0);
}