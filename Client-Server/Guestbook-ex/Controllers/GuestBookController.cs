using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

using Guestbook.Models;

namespace Guestbook.Controllers
{
    public class GuestBookController : Controller
    {
        private Guestbook.Models.GuestbookContext _db = new Guestbook.Models.GuestbookContext();
        //
        // GET: /GuestBook/
        public ActionResult Index()
        {
            var mostRecentEntries =
                (from entry in _db.Entries
                 orderby entry.DateAdded descending
                 select entry).Take(20);
            ViewBag.Entries = mostRecentEntries.ToList();
            return View();
        }

        public ActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Create(Guestbook.Models.GuestbookEntry entry)
        {
            entry.DateAdded = DateTime.Now;
            _db.Entries.Add(entry);
            _db.SaveChanges();
            return RedirectToAction("Index");
        }

        public ViewResult Show(int id)
        {
            var entry = _db.Entries.Find(id);
            bool hasPermission = User.Identity.Name == entry.Name;
            ViewData["hasPermission"] = hasPermission;
            return View(entry);
        }

        public ActionResult CommentSummary()
        {
            var entries = from entry in _db.Entries
                          group entry by entry.Name
                              into groupedByName
                              orderby groupedByName.Count() descending
                              select new Guestbook.Models.CommentSummary
                                              {
                                                  NumberOfComments =
                                                  groupedByName.Count(),
                                                  UserName = groupedByName.Key
                                              };
            return View(entries.ToList());
        }

        public ActionResult Edit(int id)
        {
            var entry = _db.Entries.Find(id);
            return View(entry);
        }

        [HttpPost]
        public ActionResult Edit(Guestbook.Models.GuestbookEntry entry)
        {
            _db.Entries.Attach(entry);
            _db.Entry(entry).State = System.Data.EntityState.Modified;
            _db.SaveChanges();
            return RedirectToAction("Index");
        }
    }
}
