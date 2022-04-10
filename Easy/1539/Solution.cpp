int size = arr.size(), current = 1, next;
        
        // Edge case for the first element,
        // we count from one till the first arr element.
        while(k != 0 && current != arr[0])
        {
            current++;
            k--;
        }
        
        if(k == 0) return current - 1;
        
        // Main loop for everything else, it checks two adjacent
        // numbers and looks if they are concuring, if not we just
        // increment the current value until they are while decrementing k.
        for(int i = 0; i < size - 1; i++)
        {
            if(k == 0) return current;
            
            current = arr[i];
            next = arr[i + 1];
            
            while(next - current != 1)
            {
                k--;
                current++;
                if(k == 0) return current;
            }
        }
        
        // If passing the entire loop didn't give us a result,
        // the result will be k-numbers after the last arr member.
        return k + arr[size - 1];
