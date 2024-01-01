#include <cs50.h>
#include <stdio.h>

int main(void)

{

int start_size, end_size, current_pop, no_years = 0;
do
{
    start_size = get_int ("Start size: ");
}

while(start_size<9);



do
{
  end_size = get_int ("End size: ");

}
while (start_size>end_size);

current_pop = start_size;


while (current_pop < end_size)
{
  current_pop += current_pop/3 - current_pop/4;
  no_years ++;
}

printf("Years: %i", no_years);



}
