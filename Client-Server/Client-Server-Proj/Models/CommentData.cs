using System;
using System.Data.Entity;
using System.Linq;

namespace Client_Server_Proj.Models
{
    public class CommentData : DbContext
    {
        public CommentData() : base("Client-Server-Proj")
        {
        }

        public DbSet<CommentEntry> Entries { get; set; }
    }
}