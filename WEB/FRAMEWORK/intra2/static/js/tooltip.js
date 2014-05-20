$(document).ready(function () {
  $("span.question").hover(function () {
    $(this).append('<div class="tooltip"><p>'+ $(this).attr("data")+'</p></div>');
  }, function () {
    $("div.tooltip").remove();
  });
});