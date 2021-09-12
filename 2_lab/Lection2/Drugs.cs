using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lection2
{
    class Drugs
    {
        string drugsName;
        int amount;
        int price;
        internal Drugs(string drugsName, int amount, int price)
        {
            this.drugsName = drugsName;
            this.amount = amount;
            this.price = price; 
        }
        public override string ToString()
        {
            return "Название лекарства: " + drugsName.ToString() + "\nКоличесвто: " + amount.ToString() + "\nЦена: " + price.ToString();
        }
        public override bool Equals(object obj)
        {

            if ((obj == null) || !this.GetType().Equals(obj.GetType()))
            {
                return false;
            }
            else {
                Drugs n = (Drugs)obj;
                return (drugsName == n.drugsName) && (amount==n.amount) && (price==n.price);
            }
        }
    }
}
