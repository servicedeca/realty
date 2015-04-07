<div class="container fin last-block">
<div class="col-xs-12 table-block text-center zero-padding">
  <br><br><br>
  <table class="table issue-table display" id="complex">
    <tbody>

    <tr>
      <th id="bn">Квартира</th>
      <?php if (isset($number_apartment)): ?>
        <?php foreach ($number_apartment as $val): ?>
          <td scope="row" class="no-hover anchor" onClick="location.href='apartment.html' ">
            <a href="#" title="Посмотреть квартиру">
              <div class="flat-number profile-flat-number">
                <?php print $val?>
              </div>
            </a>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>


    <tr>
      <th>Адресс</th>
      <?php if (isset($address)): ?>
        <?php foreach ($address as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Секция</th>
      <?php if (isset($sections)): ?>
        <?php foreach ($sections as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Комнаты</th>
      <?php if (isset($rooms)): ?>
        <?php foreach ($rooms as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Этаж</th>
      <?php if (isset($floor)): ?>
        <?php foreach ($floor as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th >S м<sup>2</sup></th>
      <?php if (isset($sq)): ?>
        <?php foreach ($sq as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Цена т.р./м<sup>2</sup></th>
      <?php if (isset($price)): ?>
        <?php foreach ($price as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
          <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Стоимость</th>
      <?php if (isset($coast)): ?>
        <?php foreach ($coast as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Парковка</th>
      <?php if (isset($parking)): ?>
        <?php foreach ($parking as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    <tr>
      <th>Балкон</th>
      <?php if (isset($balcony)): ?>
        <?php foreach ($balcony as $val): ?>
          <td class="anchor" onClick="location.href='apartment.html' ">
            <?php print $val; ?>
          </td>
        <?php endforeach; ?>
      <?php endif; ?>
    </tr>

    </tbody>
  </table>
</div>
</div>