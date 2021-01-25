using System;
using System.Data.Entity;
using System.Linq;

namespace Client_Server_Proj.Models
{
    public class CommentEntry : DbContext
    {
       
        public int ID { get; set; }
        public string Email { get; set; }
        public string Comment { get; set; }
        public DateTime CurrDate { get; set; }

    }
}