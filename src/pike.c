int main()
{
	while(1)
	{
		/* Sync with Linux Partition */		
		if( SHRD_MEM_START != 0x01 )
		{
			nanosleep(4);
			continue;
		}
		else
		{
			/* Application code */
		}

	}	
	return 0;
}
