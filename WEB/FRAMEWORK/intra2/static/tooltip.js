$(document).ready(function () {
  $("span.question").hover(function () {
    $(this).append('<div class="tooltip"><p>This is a tooltip. It is typically used to explain something to a user without taking up space on the page.</p></div>');
  }, function () {
    $("div.tooltip").remove();
  });
});